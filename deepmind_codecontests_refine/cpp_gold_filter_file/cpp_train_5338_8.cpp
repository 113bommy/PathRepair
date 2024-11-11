#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int a[100005];
void nhap() {
  cin >> n;
  for (int i = int(1); i <= int(n); i++) cin >> a[i];
  sort(a + 1, a + n + 1);
}
void xuli() {
  vector<int> ans;
  int l = 1, r = n;
  int dem = 0;
  ans.push_back(a[r]);
  r--;
  while (l < r) {
    dem++;
    ans.push_back(a[l]);
    l++;
    ans.push_back(a[r]);
    r--;
  }
  if (l == r) ans.push_back(a[l]);
  cout << dem << "\n";
  for (int u : ans) cout << u << ' ';
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  nhap();
  xuli();
}
