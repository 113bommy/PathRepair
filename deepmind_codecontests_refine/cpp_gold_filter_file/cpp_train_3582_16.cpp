#include <bits/stdc++.h>
using namespace std;
void change_value(long long int &n) {
  if (n == 1)
    ++n;
  else if (n == 2)
    --n;
}
int main() {
  long long int m;
  cin >> m;
  long long int n = 2 * m;
  vector<pair<long long int, long long int>> numbers(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> numbers[i].first;
    numbers[i].second = i;
  }
  sort(numbers.begin(), numbers.end());
  long long int singleton = 1;
  long long int multi = 1;
  vector<long long int> heaps(n, 0);
  long long int i = 0;
  vector<long long int> counter(2, 0);
  while (i < n) {
    if (i == 0 || numbers[i].first != numbers[i - 1].first) {
      if (numbers[i].first != numbers[i + 1].first || i == n - 1) {
        heaps[i] = singleton;
        counter[singleton - 1]++;
        change_value(singleton);
      } else if (numbers[i].first == numbers[i + 1].first) {
        heaps[i] = multi;
        counter[multi - 1]++;
        change_value(multi);
        ++i;
        heaps[i] = multi;
        counter[multi - 1]++;
        change_value(multi);
      }
    }
    ++i;
  }
  long long int max = counter[0] * counter[1];
  for (long long int j = 0; j < n; ++j) {
    if (heaps[j] == 0 && counter[0] != m) {
      heaps[j] = 1;
      counter[0]++;
    } else if (heaps[j] == 0 && counter[0] == m) {
      heaps[j] = 2;
    }
  }
  long long int temp;
  for (long long int j = 0; j < n; ++j) {
    temp = numbers[j].second;
    numbers[j].second = heaps[j];
    numbers[j].first = temp;
  }
  sort(numbers.begin(), numbers.end());
  cout << max << endl;
  for (long long int j = 0; j < n; ++j) {
    cout << numbers[j].second << " ";
  }
  cout << endl;
  return 0;
}
