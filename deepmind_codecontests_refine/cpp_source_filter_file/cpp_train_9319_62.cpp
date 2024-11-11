#include <bits/stdc++.h>
using namespace std;
vector<long long int> a;
vector<long long int> b;
long long int fa(int l, int r) {
  long long int ret = 0;
  for (int i = l; i <= r; ++i) ret |= a[i];
  return ret;
}
long long int fb(int l, int r) {
  long long int ret = 0;
  for (int i = l; i <= r; ++i) ret |= b[i];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  long long int aux, ans;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> aux;
    a.push_back(aux);
  }
  for (int i = 0; i < n; ++i) {
    cin >> aux;
    b.push_back(aux);
  }
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      ans = max(ans, fa(i, j) + fb(i, j));
    }
  cout << ans << "\n";
  return 0;
}
