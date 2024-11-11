#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> basis;
void add(int x) {
  for (int& a : basis)
    if (a & -a & x) x ^= a;
  if (x == 0) return;
  for (int& a : basis)
    if (x & -x & a) a ^= x;
  basis.emplace_back(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    add(x ^= a);
  }
  if (x)
    cout << basis.size();
  else
    cout << "-1";
}
