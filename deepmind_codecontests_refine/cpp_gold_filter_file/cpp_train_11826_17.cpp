#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, count = 0;
  vector<long long int> v;
  long long int min = 2 * 1000000001;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (long long int i = 0; i < n - 1; i++) {
    if (abs(v[i] - v[i + 1]) <= min) {
      min = abs(v[i] - v[i + 1]);
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (abs(v[i] - v[i + 1]) == min) {
      count++;
    }
  }
  cout << min << " " << count << endl;
  return 0;
}
