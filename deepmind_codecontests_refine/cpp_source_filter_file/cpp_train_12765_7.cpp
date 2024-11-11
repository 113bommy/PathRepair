#include <bits/stdc++.h>
using namespace std;
struct St {
  int h, nom, type;
};
bool operator<(St a, St b) { return a.h > b.h; }
St st[200009];
long long s[100009], a[100009], b[100009], v[100009], ans1, ans2, S, n, n2, B,
    C, A, D, m, ANS;
long long pas(long long K) {
  long long M, MM, ans, W;
  M = S * K;
  MM = m * S - M;
  ans = 0;
  for (int i = 1; i <= n; i++) v[i] = s[i];
  for (int i = 1; i <= n2; i++) {
    if (v[st[i].nom] == 0) continue;
    if (st[i].type == 2) {
      if (MM == 0) continue;
      W = v[st[i].nom];
      if (W > MM) W = MM;
      ans = ans + W * b[st[i].nom];
      MM = MM - W;
      v[st[i].nom] = v[st[i].nom] - W;
    }
    if (v[st[i].nom]) {
      if (st[i].type == 1) {
        if (M == 0) continue;
        W = v[st[i].nom];
        if (W > M) W = M;
        ans = ans + W * a[st[i].nom];
        M = M - W;
        v[st[i].nom] = v[st[i].nom] - W;
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> S;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> a[i] >> b[i];
    n2++;
    st[n2].h = a[i] - b[i];
    st[n2].nom = i;
    st[n2].type = 1;
    n2++;
    st[n2].h = b[i] - a[i];
    st[n2].nom = i;
    st[n2].type = 2;
    m = m + s[i];
  }
  sort(st + 1, st + n2 + 1);
  if (n == 1) {
    if (a[1] >= b[1])
      cout << S * a[1] << endl;
    else
      cout << S * b[1] << endl;
    return 0;
  }
  if (m % S == 0)
    m = m / S;
  else
    m = m / S + 1;
  A = 0;
  B = m;
  while (A < B) {
    C = A + (B - A) / 3;
    D = B - (B - A) / 3;
    ans1 = pas(C);
    ans2 = pas(D);
    ANS = max(ANS, max(ans1, ans2));
    if (ans1 == ans2) {
      A = C + 1;
      B = D;
    } else if (ans1 < ans2)
      A = C + 1;
    else if (ans1 > ans2)
      B = D - 1;
  }
  cout << ANS << endl;
  return 0;
}
