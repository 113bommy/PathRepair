#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
set<int> sett;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < N; ++i) sett.insert(i);
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if ((i == 1 && a != 0) || (*sett.begin()) < a) return cout << i, 0;
    if (sett.count(a)) sett.erase(a);
  }
  cout << -1;
  return 0;
}
