#include <bits/stdc++.h>
using namespace std;
int T, N, A, w[100100], G, CNT;
long long ans;
string s;
int main() {
  scanf("%d %d", &N, &A);
  map<int, int> m;
  cin >> s;
  for (int i = (0); i < (N); i++) w[i] = s[i] - 'a';
  for (int i = (0); i < (N); i++) {
    scanf("%d", &w[i]);
    w[i] = (m.count(w[i]) ? m[w[i]] : m[w[i]] = ++CNT);
  }
  long long add = 0;
  for (int i = (0); i < (N); i++)
    if (!i || w[i - 1] != w[i]) {
      G++;
      add += -N + 1;
    }
  ans = 1ll * G * N * A;
  ans = (ans + add);
  for (int i = (1); i < (N); i++) {
    int a = w[i - 1], b = w[i];
    if (a == b) continue;
    if (i - 2 < 0 || w[i - 2] != b) {
      int j = i + 1;
      while (j < N) {
        int n = (j - i) % 2 ? a : b;
        if (w[j] == n)
          j++;
        else
          break;
      }
      long long x = 1ll * (j - i + 1) * (j - i + 2) / 2 - 1;
      ans -= x;
    }
  }
  printf("%lld\n", ans - 1);
  return 0;
}
