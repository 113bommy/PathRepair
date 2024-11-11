#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9 + 7);
string s, cur, last;
int ans = 1;
bool cmp(int pcur, int plast) {
  if (plast - pcur > pcur + 1)
    return false;
  else if (plast - pcur < pcur + 1)
    return true;
  else {
    for (int i = 0; i < int(pcur + 1); i++) {
      if (s[i] > s[pcur + 1 + i])
        return true;
      else if (s[i] < s[pcur + 1 + i])
        return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  int pcur = s.size() - 1, plast = pcur;
  while (pcur > 0) {
    while (pcur >= 0 && s[pcur] == '0') pcur--;
    pcur--;
    bool ok = false;
    while (pcur >= 0) {
      ok = cmp(pcur, plast);
      if (ok) break;
      pcur--;
    }
    if (ok) ans++;
    plast = pcur;
  }
  printf("%d", ans);
  return 0;
}
