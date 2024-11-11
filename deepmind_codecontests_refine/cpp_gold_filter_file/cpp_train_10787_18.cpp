#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const int Inf = 100000;
const int mod = 1000000007;
const double Pi = acos(-1);
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long n;
int T[200005][19], L[200005], a[200005];
vector<int> N[35];
long long ans = 0;
int Max(int x, int y) {
  if (a[x] < a[y]) {
    return y;
  } else {
    return x;
  }
}
int M(int l, int r) {
  int temp = L[r - l + 1];
  return Max(T[l][temp], T[r + 1 - (1 << temp)][temp]);
}
void DNC(int l, int r) {
  if (l >= r) {
    return;
  }
  int temp = M(l, r);
  int ll = l - 1, rr = r + 1;
  for (int i = 30; i >= 0; i--) {
    if (a[temp] & (1 << i) or N[i].empty()) {
      continue;
    }
    int lll = 0, rrr = (int)N[i].size() - 1;
    while (lll < rrr) {
      int mid = (lll + rrr + 1) >> 1;
      if (N[i][mid] > temp) {
        rrr = mid - 1;
      } else {
        lll = mid;
      }
    }
    if (N[i][lll] <= temp) ll = max(ll, N[i][lll]);
    lll = 0, rrr = (int)N[i].size() - 1;
    while (lll < rrr) {
      int mid = (lll + rrr) >> 1;
      if (N[i][mid] < temp) {
        lll = mid + 1;
      } else {
        rrr = mid;
      }
    }
    if (N[i][rrr] >= temp) rr = min(rr, N[i][rrr]);
  }
  ll++;
  rr--;
  ans += 1ll * (rr - temp + 1) * (temp - ll + 1);
  ans--;
  DNC(l, temp - 1);
  DNC(temp + 1, r);
}
int main() {
  Fastio();
  cin >> n;
  L[0] = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    T[i][0] = i;
    for (int j = 30; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        N[j].emplace_back(i);
      }
    }
  }
  for (int i = 1; i <= 18; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      T[j][i] = Max(T[j][i - 1], T[j + (1 << (i - 1))][i - 1]);
    }
  }
  for (int i = 1; i <= 200000; i++) {
    L[i] = L[i >> 1] + 1;
  }
  DNC(0, n - 1);
  ans = 1ll * n * (n - 1) / 2 - ans;
  cout << ans;
}
