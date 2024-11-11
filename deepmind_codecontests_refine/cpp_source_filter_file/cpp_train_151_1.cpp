#include <bits/stdc++.h>
using namespace std;
string a, b, c;
int cnta[26], bkp[26], cntb[26], cntc[26];
int calc(int cnt[]) {
  int ans = int(1e5) + 10;
  for (int i = 0; i < 26; i++)
    if (cnt[i]) ans = min(ans, cnta[i] / cnt[i]);
  for (int i = 0; i < 26; i++) cnta[i] -= ans * cnt[i];
  return ans;
}
void reset() {
  for (int i = 0; i < 26; i++) cnta[i] = bkp[i];
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b >> c;
  for (int i = 0; i < a.size(); i++) cnta[a[i] - 'a']++, bkp[a[i] - 'a']++;
  for (int i = 0; i < b.size(); i++) cntb[b[i] - 'a']++;
  for (int i = 0; i < c.size(); i++) cntc[c[i] - 'a']++;
  int pb, maxb = calc(cntb), pc, ocb = 0, occ = 0;
  for (pb = 1; pb <= maxb; pb++) {
    reset();
    for (int i = 0; i < 26; i++) cnta[i] -= pb * cntb[i];
    pc = calc(cntc);
    if (pb + pc > ocb + occ) ocb = pb, occ = pc;
  }
  pb = ocb, pc = occ;
  reset();
  for (int i = 0; i < pb; i++) cout << b;
  for (int i = 0; i < pc; i++) cout << c;
  for (int i = 0; i < 26; i++)
    for (; (cnta[i] - (pb * cntb[i] + pc * cntc[i])); cnta[i]--)
      cout << char(i + 'a');
  return (0);
}
