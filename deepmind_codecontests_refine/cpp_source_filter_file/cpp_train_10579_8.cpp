#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 1e7 + 9;
int lp[N], phi[N], n;
long long par[N];
vector<int> pr;
long long path[4];
int main() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!lp[i])
      lp[i] = i, phi[i] = i - 1, pr.push_back(i);
    else {
      if (lp[i] == lp[i / lp[i]])
        phi[i] = phi[i / lp[i]] * lp[i];
      else
        phi[i] = phi[i / lp[i]] * (lp[i] - 1);
    }
    for (int j = 0; j < (int)pr.size() and pr[j] <= lp[i] and i * pr[j] < N;
         j++)
      lp[i * pr[j]] = pr[j];
  }
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) path[1] += i - 1 - phi[i];
  for (int i = 2; i <= n; i++) par[lp[i]]++;
  for (int i = 2; i <= n; i++) par[i] += par[i - 1];
  for (int i = 2; i <= n; i++) {
    path[2] += par[n / lp[i]];
    if (lp[i] * lp[i] <= n) path[2]--;
  }
  assert(path[2] % 2 == 0);
  path[2] /= 2;
  path[2] -= path[1];
  for (int i = 2; i <= n; i++)
    if (lp[i] * 2 <= n) path[3] += par[n / 2] - 1;
  assert(path[3] % 2 == 0);
  path[3] /= 2;
  path[3] -= path[2] + path[1];
  long long ans = 0;
  for (int i = 1; i <= 3; i++) ans += path[i] * 1LL * i;
  printf("%lld\n", ans);
  return 0;
}
