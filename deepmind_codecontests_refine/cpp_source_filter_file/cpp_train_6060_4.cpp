#include <bits/stdc++.h>
using namespace std;
class DebugStream {
} LOG;
template <typename T>
DebugStream& operator<<(DebugStream& s, const T&) {
  return s;
}
mt19937 rnd(time(NULL));
const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20,
          bs = 29;
int amo[bs], cpy[bs], ts[2][3], llev[bs];
pair<long long, long long> prs[3];
int smb(int w, int* arr) {
  int ret = 0;
  for (int i = 0; i < 8; i++)
    if (1 << w & i) ret += arr[i];
  return ret;
}
void reduc(pair<long long, long long>& x) {
  if (!x.first)
    x.second--;
  else
    x.first--;
}
bool ispos() {
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 3; b++)
      if (ts[a][b] < 0) return false;
  for (int a = 0; a < 2; a++, LOG << '\n')
    for (int b = 0; b < 3; b++) LOG << ts[a][b] << ' ';
  memset(cpy, 0, sizeof cpy);
  for (int i = 0; i < 3; i++) cpy[1 << i ^ 7] = amo[1 << i ^ 7];
  memset(llev, 0, sizeof llev);
  for (int i = 0; i < 3; i++) {
    LOG << "smb is " << i << ' ' << smb(i, amo) << '\n';
    if (smb(i, amo) - ts[1][i] > ts[0][i]) return false;
    prs[i].first = max(0, smb(i, amo) - ts[1][i] - amo[1 << i]);
    prs[i].second = ts[0][i] - prs[i].first;
    LOG << prs[i].first << ' ' << prs[i].second << '\n';
  }
  while (prs[0].first > 0 || prs[1].first > 0 || prs[2].first > 0) {
    int yie = -1;
    for (int i = 0; i < 3; i++)
      if (cpy[1 << i ^ 7] && (yie == -1 || prs[i] < prs[yie])) yie = i;
    if (yie == -1) break;
    cpy[1 << yie ^ 7]--, llev[1 << yie ^ 7]++;
    for (int i = 0; i < 3; i++)
      if (i != yie) reduc(prs[i]);
  }
  if (prs[0].first > 0 || prs[1].first > 0 || prs[2].first > 0 ||
      min(min(prs[0].second, prs[1].second), prs[2].second) < 0)
    return false;
  for (int i = 0; i < 3; i++)
    while (smb(i, llev) < smb(i, amo) - ts[1][i]) llev[1 << i]++;
  return true;
}
bool solve() {
  int saiz = amo[7];
  amo[7] = 0;
  for (int j = 1; j <= 6; j++)
    if (j == 1 || j == 2 || j == 4) LOG << amo[j] << ' ';
  LOG << '\n';
  for (int j = 6; j >= 1; j--)
    if (j == 3 || j == 5 || j == 6) LOG << amo[j] << ' ';
  LOG << "\n\n\n";
  for (int j = 0; j <= saiz; j++) {
    for (int k = 0; k < 3; k++) ts[0][k] -= (saiz - j), ts[1][k] -= j;
    if (ispos()) {
      llev[7] = amo[7] - j;
      return true;
    }
    LOG << '\n';
    for (int k = 0; k < 3; k++) ts[0][k] += (saiz - j), ts[1][k] += j;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) cin >> ts[i][j];
      reverse(ts[i], ts[i] + 3);
    }
    for (int j = 7; j >= 1; j--) cin >> amo[j];
    if (solve()) {
      for (int i = 7; i >= 1; i--) cout << llev[i] << ' ';
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
