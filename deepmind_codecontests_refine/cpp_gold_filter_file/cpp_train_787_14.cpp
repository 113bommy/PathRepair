#include <bits/stdc++.h>
using namespace std;
long long INV2 = 500000004;
long long INV6 = 166666668;
long long power(long long a, long long b, long long c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % c;
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 3e5 + 5;
string a, b;
int ha[30], hb[30];
char ans[N];
int main() {
  cin >> a >> b;
  int len = a.size();
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  for (int i = 0; i < len; ++i) {
    ha[a[i] - 'a']++;
  }
  for (int i = 0; i < len; ++i) {
    hb[b[i] - 'a']++;
  }
  int turns_o = ceil(len / 2.0), turns_i = len / 2;
  int st = 0, en = len - 1, ol, ig;
  int oo = 0, eo = turns_o - 1, oi = turns_o, ei = len - 1;
  for (int i = 0; i < len; ++i) {
    int ibadi = b[ei] - 'a', ichoti = b[oi] - 'a';
    int obadi = a[eo] - 'a', ochoti = a[oo] - 'a';
    if (i & 1) {
      if (ibadi > ochoti) {
        ans[st++] = (char)(ibadi + 'a');
        ei--;
      } else if (ibadi <= ochoti) {
        ans[en--] = (char)(ichoti + 'a');
        oi++;
      }
    } else {
      if (ochoti < ibadi) {
        ans[st++] = (char)(ochoti + 'a');
        oo++;
      } else if (ochoti >= ibadi) {
        ans[en--] = (char)(obadi + 'a');
        eo--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
