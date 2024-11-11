#include <bits/stdc++.h>
using namespace std;
map<long long, long long> M;
int main() {
  long long N, K;
  cin >> N;
  vector<long long> f(N), acm(N), v(N);
  for (int i = (0); i < (N); i++) {
    cin >> v[i];
    M[v[i]] = i + 1;
  }
  sort((v).begin(), (v).end());
  for (int i = (0); i < (N); i++)
    if (i == 0)
      acm[i] = v[i];
    else
      acm[i] = acm[i - 1] + v[i];
  cin >> K;
  long long l = 0, r = K - 1;
  while (r - l > 0) {
    f[K - 1] += (r - l) * (v[r] - v[l]);
    r--;
    l++;
  }
  pair<long long, long long> ans(f[K - 1], 0);
  for (int i = (K); i < (N); i++) {
    f[i] = f[i - 1] + (K - 1) * v[i] + (K - 1) * v[i - K] -
           2 * (acm[i - 1] - acm[i - K]);
    ans = min(ans, make_pair(f[i], (long long)(i - K + 1)));
  }
  for (int i = (ans.second); i < (ans.second + K); i++) cout << M[v[i]] << " ";
}
