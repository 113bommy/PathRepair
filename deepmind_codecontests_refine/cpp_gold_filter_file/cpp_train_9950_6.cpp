#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
string a, b;
int pref[maxN], suff[maxN];
int main() {
  cin >> a >> b;
  int l1 = a.size(), l2 = b.size();
  int j = 0;
  int llast = l2 - 1;
  for (int i = 0; i < l2; i++) {
    while (b[i] != a[j] && j < l1) j++;
    if (j == l1) llast = i - 1;
    pref[i] = j;
    j++;
  }
  j = l1 - 1;
  int rlast = 0;
  for (int i = l2 - 1; i >= 0; i--) {
    while (b[i] != a[j] && j >= 0) j--;
    if (j == -1) rlast = i + 1;
    suff[i] = j;
    j--;
  }
  if (llast == -1 && rlast == l2) {
    cout << "-\n";
    return 0;
  }
  j = rlast;
  int x = -1, y = rlast;
  int ans = l2 - rlast;
  for (int i = 0; i <= llast; i++) {
    while (j < l2 && (pref[i] >= suff[j] || i >= j)) j++;
    if (i + 1 + l2 - j > ans) {
      x = i;
      y = j;
      ans = i + 1 + l2 - j;
    }
  }
  for (int i = 0; i <= x; i++) cout << b[i];
  for (int i = y; i < l2; i++) cout << b[i];
  cout << '\n';
  return 0;
}
