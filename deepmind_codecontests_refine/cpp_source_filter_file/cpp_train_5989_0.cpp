#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 21;
int col[maxn], row[maxn];
int main() {
  string second;
  int n, ans;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> second;
    for (int j = 0; j < n; j++) {
      if (second[j] == 'C') ans += col[i] + row[j], col[i]++, row[j]++;
    }
  }
  cout << ans << endl;
  return 0;
}
