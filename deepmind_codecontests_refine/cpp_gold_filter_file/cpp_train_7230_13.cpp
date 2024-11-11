#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const long long MOD = 1000000007;
long long ABS(long long a) {
  if (a < 0)
    return a * (-1);
  else
    return a;
}
int bit[1 << 17];
unsigned int A[32][200010], B[32][200010];
void gen(unsigned int A[32][200010], string a) {
  for (int i = 0; i < 32; i++) {
    unsigned int c = 0;
    int itt = 0;
    for (int j = 0; j + i < (int)((a).size()); j++) {
      c *= 2;
      c += (a[i + j] - '0');
      if (j % 32 == 31) {
        A[i][itt++] = c;
        c = 0;
      }
    }
  }
}
int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < (1 << 16); i++) {
    int t = i;
    int kk = 0;
    while (t) {
      kk += (t % 2);
      t /= 2;
    }
    bit[i] = kk;
  }
  gen(A, a);
  gen(B, b);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int c1, c2, len;
    scanf("%d%d%d", &c1, &c2, &len);
    int ans = 0;
    int s1 = c1 % 32;
    int s2 = c2 % 32;
    int st1 = c1 / 32;
    int st2 = c2 / 32;
    int end1 = st1 + len / 32;
    int end2 = st2 + len / 32;
    for (int j = st1; j < end1; j++) {
      unsigned int tem = A[s1][j];
      tem ^= B[s2][st2++];
      ans += bit[(tem >> 16)];
      ans += bit[(tem & 65535)];
    }
    int f1 = end1 * 32 + s1;
    int f2 = end2 * 32 + s2;
    end1 = c1 + len;
    end2 = c2 + len;
    for (int j = f1; j < end1; j++) {
      if (a[j] != b[f2++]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
