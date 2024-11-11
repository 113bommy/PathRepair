#include <bits/stdc++.h>
using namespace std;
vector<long long int> elements;
int main() {
  long long int n, first = 0, second = 0;
  cin >> n;
  while (n--) {
    long long int m;
    cin >> m;
    for (int i = 1; i <= m / 2; i++) {
      long long int a;
      cin >> a;
      first += a;
    }
    if (m & 1) {
      long long int a;
      cin >> a;
      elements.push_back(a);
    }
    for (int i = 1; i <= m / 2; i++) {
      long long int a;
      cin >> a;
      second += a;
    }
  }
  sort(elements.begin(), elements.end());
  long long int turn = 1;
  for (int i = (long long int)elements.size() - 1; i >= 0; i--) {
    if (turn)
      first += elements[i];
    else
      second = elements[i];
    turn = turn ^ 1;
  }
  cout << first << " " << second << endl;
  return 0;
}
