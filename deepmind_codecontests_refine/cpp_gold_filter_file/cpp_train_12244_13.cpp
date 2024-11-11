#include <bits/stdc++.h>
using namespace std;
int r[1000];
bool br[1000];
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (auto i : s) r[i]++;
  int m = 0;
  for (int i = 0; i < 1000; i++) m = max(m, r[i]);
  cout << (m > k ? "NO" : "YES");
}
