#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
long long n, h, a[N];
vector<long long> v;
bool check(int num) {
  v.clear();
  for (int i = 1; i <= num; i++) {
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  long long all = 0;
  for (int i = v.size() - 1; i >= 0; i -= 2) {
    all += v[i];
  }
  return all <= h;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 2;
  for (int i = 2; i <= n; i++) {
    if (check(i)) ans = i;
  }
  cout << ans << endl;
}
