#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 10;
const int inf = 1e9 + 10;
const int N = 1e6 + 10;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int x = a[0];
  vector<int> rSimple;
  for (int i = 2; i * i <= a[0]; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      rSimple.push_back(i);
    }
  if (x != 1) rSimple.push_back(x);
  x = b[0];
  for (int i = 2; i * i <= b[0]; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      rSimple.push_back(i);
    }
  if (x != 1) rSimple.push_back(x);
  sort(rSimple.begin(), rSimple.end());
  rSimple.push_back(-1);
  vector<int> Simple;
  for (int i = 1; i < rSimple.size(); i++)
    if (rSimple[i] != rSimple[i - 1]) Simple.push_back(rSimple[i]);
  for (auto del : Simple) {
    int flag = 1;
    for (int i = 0; i < n; i++)
      if (a[i] % del != 0 and b[i] % del != 0) flag = 0;
    if (flag) return cout << del << "\n", 0;
  }
  cout << -1 << "\n";
  return 0;
}
