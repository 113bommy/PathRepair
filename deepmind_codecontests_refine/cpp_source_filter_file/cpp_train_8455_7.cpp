#include <bits/stdc++.h>
using namespace std;
int pal[2502][2502];
int lps(int seq[], int i, int j) {
  if (pal[i][j] != -1) return pal[i][j];
  if (i > j) return pal[i][j] = 0;
  if (i == j) return pal[i][j] = 1;
  if (seq[i] == seq[j]) return pal[i][j] = 2 + lps(seq, i + 1, j - 1);
  return pal[i][j] = max(lps(seq, i, j - 1), lps(seq, i + 1, j));
}
void Q2_V2() {
  int t;
  cin >> t;
  while (t--) {
    memset(pal, -1, sizeof(pal));
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (lps(a, 0, n - 1) >= 3 ? "YES" : "NO") << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Q2_V2();
  return 0;
}
