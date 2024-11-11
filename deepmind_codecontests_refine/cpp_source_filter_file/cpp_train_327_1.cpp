#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    S = "*" + S;
    int N = (int)S.size();
    vector<int> h(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
      h[i] = h[i - 1];
      v[i] = v[i - 1];
      if (S[i] == 'D') {
        h[i]++;
      }
      if (S[i] == 'A') {
        h[i]--;
      }
      if (S[i] == 'W') {
        v[i]++;
      }
      if (S[i] == 'S') {
        v[i]--;
      }
    }
    vector<int> ml(N + 1), mr(N + 1), mu(N + 1), md(N + 1);
    mr[N] = h[N];
    ml[N] = h[N];
    mu[N] = v[N];
    md[N] = v[N];
    for (int i = N - 1; i >= 0; i--) {
      mr[i] = max(h[i], mr[i + 1]);
      ml[i] = min(h[i], ml[i + 1]);
      mu[i] = max(v[i], mu[i + 1]);
      md[i] = min(v[i], md[i + 1]);
    }
    long long ans = 1LL * (abs(md[0]) + mu[0] + 1) * (abs(ml[0]) + mr[0] + 1);
    int ch = 0, cv = 0;
    int cl = 0, cr = 0, cu = 0, cd = 0;
    for (int i = 0; i < N; i++) {
      long long R = 1LL *
                    (1 + max({cr, ch + 1, mr[i] + 1}) +
                     abs(min({cl, ch + 1, ml[i] + 1}))) *
                    (1 + mu[0] + abs(md[0]));
      long long L = 1LL *
                    (1 + max({cr, ch - 1, mr[i] - 1}) +
                     abs(min({cl, ch - 1, ml[i] - 1}))) *
                    (1 + mu[0] + abs(md[0]));
      long long U = 1LL *
                    (1 + max({cu, cv + 1, mu[i] + 1}) +
                     abs(min({cd, cv + 1, md[i] + 1}))) *
                    (1 + mr[0] + abs(ml[0]));
      long long D = 1LL *
                    (1 + max({cu, cv + 1, mu[i] - 1}) +
                     abs(min({cd, cv - 1, md[i] - 1}))) *
                    (1 + mr[0] + abs(ml[0]));
      ans = min({ans, L, R, U, D});
      if (S[i] == 'D') {
        ch++;
        cr = max(ch, cr);
      }
      if (S[i] == 'A') {
        ch--;
        cl = min(ch, cl);
      }
      if (S[i] == 'W') {
        cv++;
        cu = max(cv, cu);
      }
      if (S[i] == 'S') {
        cv--;
        cd = min(cv, cd);
      }
    }
    cout << ans << '\n';
  }
}
