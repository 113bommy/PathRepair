#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
char ibuf[4096];
int ipt = 4096;
int readUInt() {
  while (ipt < 4096 && ibuf[ipt] < '0') ipt++;
  if (ipt == 4096) {
    fread(ibuf, 1, 4096, stdin);
    ipt = 0;
    while (ipt < 4096 && ibuf[ipt] < '0') ipt++;
  }
  int n = 0;
  char neg = 0;
  if (ipt != 0 && ibuf[ipt - 1] == '-') neg = 1;
  while (ipt < 4096 && ibuf[ipt] >= '0') n = (n * 10) + (ibuf[ipt++] - '0');
  if (ipt == 4096) {
    fread(ibuf, 1, 4096, stdin);
    ipt = 0;
    while (ipt < 4096 && ibuf[ipt] >= '0') n = (n * 10) + (ibuf[ipt++] - '0');
  }
  return neg ? -n : n;
}
int main() {
  int n;
  int m;
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  long long int csum = 0;
  long long int ncsum = 0;
  long long int mcsum = 0;
  int dni = 2;
  int c[n][m];
  for (int ni = 0; ni < n; ni++) {
    int dmi = 2;
    for (int mi = 0; mi < m; mi++) {
      scanf("%d", &c[ni][mi]);
      ;
      csum += c[ni][mi];
      ncsum += dni * c[ni][mi];
      mcsum += dmi * c[ni][mi];
      dmi += 4;
    }
    dni += 4;
  }
  if (csum == 0) {
    printf("0\n0 0\n");
    return 0;
  }
  int nres1 = (ncsum / csum) / 4;
  int mres1 = (mcsum / csum) / 4;
  int nres2 = nres1 + 1;
  int mres2 = mres1 + 1;
  long long int tcostn1 = 0;
  long long int tcostn2 = 0;
  long long int tcostm1 = 0;
  long long int tcostm2 = 0;
  int posn1 = 4 * nres1;
  int posm1 = 4 * mres1;
  int posn2 = 4 * nres2;
  int posm2 = 4 * mres2;
  dni = 2;
  for (int ni = 0; ni < n; ni++) {
    int dmi = 2;
    for (int mi = 0; mi < m; mi++) {
      tcostn1 += c[ni][mi] * (long long int)((dni - posn1) * (dni - posn1));
      tcostn2 += c[ni][mi] * (long long int)((dni - posn2) * (dni - posn2));
      tcostm1 += c[ni][mi] * (long long int)((dmi - posm1) * (dmi - posm1));
      tcostm2 += c[ni][mi] * (long long int)((dmi - posm2) * (dmi - posm2));
      dmi += 4;
    }
    dni += 4;
  }
  vector<pair<long long int, pair<int, int> > > rl;
  rl.push_back(make_pair(tcostn1 + tcostm1, make_pair(nres1, mres1)));
  rl.push_back(make_pair(tcostn1 + tcostm2, make_pair(nres1, mres2)));
  rl.push_back(make_pair(tcostn2 + tcostm1, make_pair(nres2, mres1)));
  rl.push_back(make_pair(tcostn2 + tcostm2, make_pair(nres2, mres2)));
  sort(rl.begin(), rl.end());
  printf("%I64d\n%d %d\n", rl[0].first, rl[0].second.first,
         rl[0].second.second);
  return 0;
}
