#include <bits/stdc++.h>
using namespace std;
void printv(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long int> v;
  long long int x;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  long long int max_el = v[n - 1];
  long long int sec_max = v[n - 2];
  ans = ((max_el * k + sec_max) * (m / (k + 1))) + (max_el * k * (m % (k + 1)));
  cout << ans << endl;
  return 0;
}
