#include <bits/stdc++.h>
using namespace std;
long long fx[4] = {1, -1, 0, 0};
long long fy[4] = {0, 0, 1, -1};
long long koijabek[6] = {1, 0, 0, -1, 0, 0};
long long koijabex[6] = {0, 1, 0, 0, -1, 0};
long long koijabey[6] = {0, 0, 1, 0, 0, -1};
long long pw(long long a, long long b) {
  long long ans = 1;
  for (long long i = 1; i <= b; ++i) ans = (ans * a);
  return ans;
}
char a[15][15][15];
long long k, n, m, bow = 0, visi[15][15][15];
void ami_biye_korbo(long long nam, long long pic, long long phn_n) {
  ++bow;
  visi[nam][pic][phn_n] = 1;
  for (int chinina = 0; chinina < 6; chinina++) {
    long long vaiya = nam + koijabek[chinina];
    long long vaiya1 = pic + koijabex[chinina];
    long long vaiya2 = phn_n + koijabey[chinina];
    if (vaiya > 0 && vaiya <= k && vaiya1 > 0 && vaiya1 <= n && vaiya2 > 0 &&
        vaiya2 <= m && visi[vaiya][vaiya1][vaiya2] == 0 &&
        a[vaiya][vaiya1][vaiya2] == '.')
      ami_biye_korbo(vaiya, vaiya1, vaiya2);
  }
}
int main() {
  {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        for (int p = 1; p <= m; p++) {
          cin >> a[i][j][p];
        }
      }
    }
    long long ogy, tom;
    cin >> ogy >> tom;
    ami_biye_korbo(1, ogy, tom);
    cout << bow << "\n";
  }
  return 0;
}
