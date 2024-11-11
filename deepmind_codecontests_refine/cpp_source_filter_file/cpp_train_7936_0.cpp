#include <bits/stdc++.h>
const unsigned long long inf = 1e18;
const int range = 1e6;
const long long inff = 1e-12;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool cmp(const pair<long long, long long>& a,
         const pair<long long, long long>& b) {
  return (a.second > b.second);
}
void vecp(vector<long long> v) {
  for (int i = 0; i < int((v).size()); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y, a, b, z, l, r, t, k;
  cin >> t;
  while (t--) {
    cin >> x;
    vector<long long> v(x);
    vector<bool> vit(8000, false);
    for (int i = 0; i < x; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    for (int i = 0; i < x - 1; i++) {
      long long sum = v[i];
      for (int j = i + 1; j < x; j++) {
        sum += v[j];
        if (sum <= 8000) {
          vit[sum] = true;
        }
      }
    }
    for (int i = 0; i < x; i++) {
      if (vit[v[i]] == true) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
