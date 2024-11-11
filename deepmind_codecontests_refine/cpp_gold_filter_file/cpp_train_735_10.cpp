#include <bits/stdc++.h>
using namespace std;
int F[100006], vis[100006];
struct node {
  int A, B, C;
  node(int a = 0, int b = 0, int c = 0) {
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(c, b);
    C = c;
    B = b;
    A = a;
  }
  bool operator<(const node& rhs) const {
    return A < rhs.A || A == rhs.A && B < rhs.B ||
           A == rhs.A && B == rhs.B && C < rhs.C;
  }
};
int d[9];
int arr[12] = {1, 3, 5, 7, 2, 3, 6, 7, 4, 5, 6, 7};
set<node> S;
void init() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      F[j]++;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 4; j < 8; j++) {
      for (int k = 8; k < 12; k++) {
        S.insert(node(arr[i], arr[j], arr[k]));
      }
    }
  }
}
long long sum2(int x) { return x * (x + 1) / 2; }
long long sum3(int x) { return x * (x + 2) * (x + 1) / 6; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int T, A, B, C;
int main() {
  init();
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &d[1], &d[2], &d[4]);
    d[3] = gcd(d[1], d[2]), d[5] = gcd(d[1], d[4]), d[6] = gcd(d[2], d[4]);
    d[7] = gcd(d[3], d[4]);
    long long ans = 0;
    for (int i = 0; i < 8; i++) d[i] = F[d[i]];
    d[3] -= d[7];
    d[5] -= d[7];
    d[6] -= d[7];
    d[1] -= d[3] + d[5] + d[7];
    d[2] -= d[3] + d[6] + d[7];
    d[4] -= d[5] + d[6] + d[7];
    for (auto it = S.begin(); it != S.end(); it++) {
      node tmp = *it;
      if (tmp.A != tmp.C && tmp.A != tmp.B && tmp.B != tmp.C) {
        ans += d[tmp.A] * d[tmp.B] * d[tmp.C];
      } else if (tmp.A == tmp.B && tmp.C != tmp.A) {
        ans += sum2(d[tmp.A]) * d[tmp.C];
      } else if (tmp.A == tmp.C && tmp.B != tmp.C) {
        ans += sum2(d[tmp.A]) * d[tmp.B];
      } else if (tmp.B == tmp.C && tmp.A != tmp.B) {
        ans += sum2(d[tmp.B]) * d[tmp.A];
      } else
        ans += sum3(d[tmp.A]);
    }
    printf("%lld\n", ans);
  }
}
