#include <bits/stdc++.h>
using namespace std;
long long sum1, sum2, sum3, sum12, sum23, sum13, sum33, ans;
long long sum[8];
int s[100001][4];
set<int> S;
vector<int> V;
int v[100001];
inline void divi(int x, int d, int p) {
  int i;
  for (i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      s[i][d] += p;
      if (v[i] == -1) {
        V.push_back(i);
      }
      if (i * i != x) {
        s[x / i][d] += p;
        if (v[x / i] == -1) {
          V.push_back(x / i);
        }
      }
      v[i] = p;
      v[x / i] = p;
    }
  }
}
inline long long f2(long long x) { return x * (x - 1ll) / 2ll + x; }
int main() {
  memset(v, -1, sizeof(v));
  int T;
  scanf("%d", &T);
  while (T > 0) {
    V.clear();
    T--;
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    sum12 = 0;
    sum23 = 0;
    sum13 = 0;
    sum33 = 0;
    S.clear();
    divi(A, 1, 1);
    divi(B, 2, 1);
    divi(C, 3, 1);
    int i, j, k;
    for (j = 0; j < V.size(); j++) {
      int i = V[j];
      if (s[i][1] == 1 && s[i][2] == 1 && s[i][3] == 1)
        sum33++;
      else if (s[i][1] == 1 && s[i][2] == 1)
        sum12++;
      else if (s[i][2] == 1 && s[i][3] == 1)
        sum23++;
      else if (s[i][1] == 1 && s[i][3] == 1)
        sum13++;
      else if (s[i][1] == 1)
        sum1++;
      else if (s[i][2] == 1)
        sum2++;
      else if (s[i][3] == 1)
        sum3++;
    }
    sum[1] = sum1;
    sum[2] = sum2;
    sum[3] = sum3;
    sum[4] = sum12;
    sum[5] = sum13;
    sum[6] = sum23;
    sum[7] = sum33;
    ans = 0;
    for (i = 1; i <= 7; i++) {
      for (j = i + 1; j <= 7; j++) {
        for (k = j + 1; k <= 7; k++) ans += sum[i] * sum[j] * sum[k];
      }
    }
    ans -= sum1 * sum2 * sum12;
    ans -= sum2 * sum3 * sum23;
    ans -= sum1 * sum3 * sum13;
    ans += f2(sum12) * (sum3 + sum13 + sum23 + sum33);
    ans += f2(sum23) * (sum1 + sum13 + sum12 + sum33);
    ans += f2(sum13) * (sum2 + sum23 + sum12 + sum33);
    ans += f2(sum33) * (sum1 + sum2 + sum3 + sum23 + sum12 + sum13);
    ans += sum33 * (sum33 - 1LL) * (sum33 - 2LL) / 6LL + sum33 * (sum33 - 1ll) +
           sum33;
    printf("%I64d\n", ans);
    divi(A, 1, -1);
    divi(B, 2, -1);
    divi(C, 3, -1);
  }
  return 0;
}
