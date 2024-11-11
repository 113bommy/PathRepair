#include <bits/stdc++.h>
using namespace std;
struct neededLetter {
  int A, C, T, G;
};
int n;
string s;
neededLetter diff[55];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    diff[i].A = s[i] - 'A';
    diff[i].C = s[i] - 'C';
    diff[i].T = s[i] - 'T';
    diff[i].G = s[i] - 'G';
    if (diff[i].C < 0) {
      diff[i].C += 26;
    }
    if (diff[i].T < 0) {
      diff[i].T += 26;
    }
    if (diff[i].G < 0) {
      diff[i].G += 26;
    }
    diff[i].A = min(diff[i].A, 'A' - s[i] < 0 ? 'A' - s[i] + 26 : 'A' - s[i]);
    diff[i].C = min(diff[i].C, 'C' - s[i] < 0 ? 'C' - s[i] + 26 : 'C' - s[i]);
    diff[i].T = min(diff[i].T, 'T' - s[i] < 0 ? 'T' - s[i] + 26 : 'T' - s[i]);
    diff[i].G = min(diff[i].G, 'G' - s[i] < 0 ? 'G' - s[i] + 26 : 'G' - s[i]);
  }
  int ans = 100000005;
  for (int i = 0; i < n - 2; ++i) {
    int currentCost = diff[i].A + diff[i + 1].C + diff[i + 2].T + diff[i + 3].G;
    ans = min(ans, currentCost);
  }
  cout << ans << '\n';
}
