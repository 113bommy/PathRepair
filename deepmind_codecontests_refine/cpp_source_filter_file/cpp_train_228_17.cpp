#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> v;
map<long long int, map<long long int, long long int> > u;
vector<long long int> w;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, k, p, q, o, l, s, t;
  string a, b;
  cin >> t;
  while (t--) {
    long long int AA = 0, BB = 0, CC = 0, DD = 0, EE = 0, FF = 0, GG = 0,
                  HH = 0, II = 0, JJ = 0, KK = 0, LLL = 0, MM = 0, NN = 0,
                  OO = 0, PP = 0, QQ = 0, RR = 0, SS = 0, TT = 0, UU = 0,
                  VV = 0, WW = 0, XX = 0, YY = 0, ZZ = 0;
    cin >> n >> m;
    cin >> a;
    for (i = 0; i < a.size(); i++) {
      v[a[i] - 'a']++;
      if (a[i] == 'a') {
        AA++;
      }
      if (a[i] == 'B') {
        BB++;
      }
      if (a[i] == 'c') {
        CC++;
      }
      if (a[i] == 'd') {
        DD++;
      }
      if (a[i] == 'e') {
        EE++;
      }
      if (a[i] == 'f') {
        FF++;
      }
      if (a[i] == 'g') {
        GG++;
      }
      if (a[i] == 'h') {
        HH++;
      }
      if (a[i] == 'i') {
        II++;
      }
      if (a[i] == 'j') {
        JJ++;
      }
      if (a[i] == 'k') {
        KK++;
      }
      if (a[i] == 'l') {
        LLL++;
      }
      if (a[i] == 'm') {
        MM++;
      }
      if (a[i] == 'n') {
        NN++;
      }
      if (a[i] == 'o') {
        OO++;
      }
      if (a[i] == 'p') {
        PP++;
      }
      if (a[i] == 'q') {
        QQ++;
      }
      if (a[i] == 'r') {
        RR++;
      }
      if (a[i] == 's') {
        SS++;
      }
      if (a[i] == 't') {
        TT++;
      }
      if (a[i] == 'u') {
        UU++;
      }
      if (a[i] == 'v') {
        VV++;
      }
      if (a[i] == 'w') {
        WW++;
      }
      if (a[i] == 'x') {
        XX++;
      }
      if (a[i] == 'y') {
        YY++;
      }
      if (a[i] == 'z') {
        ZZ++;
      }
      u[i + 1][0] = AA;
      u[i + 1][1] = BB;
      u[i + 1][2] = CC;
      u[i + 1][3] = DD;
      u[i + 1][4] = EE;
      u[i + 1][5] = FF;
      u[i + 1][6] = GG;
      u[i + 1][7] = HH;
      u[i + 1][8] = II;
      u[i + 1][9] = JJ;
      u[i + 1][10] = KK;
      u[i + 1][11] = LLL;
      u[i + 1][12] = MM;
      u[i + 1][13] = NN;
      u[i + 1][14] = OO;
      u[i + 1][15] = PP;
      u[i + 1][16] = QQ;
      u[i + 1][17] = RR;
      u[i + 1][18] = SS;
      u[i + 1][19] = TT;
      u[i + 1][20] = UU;
      u[i + 1][21] = VV;
      u[i + 1][22] = WW;
      u[i + 1][23] = XX;
      u[i + 1][24] = YY;
      u[i + 1][25] = ZZ;
    }
    for (i = 0; i < m; i++) {
      cin >> o;
      for (j = 0; j < 25; j++) {
        v[j] += u[o][j];
      }
    }
    for (i = 0; i < 26; i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
    b.clear();
    v.clear();
  }
  return 0;
}
