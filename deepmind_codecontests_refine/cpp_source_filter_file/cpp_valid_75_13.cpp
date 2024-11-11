#include <bits/stdc++.h>
using namespace std;
void debug(int a[], int n) {
  cout << "Array: [ ";
  for (auto i = 0; i != n; i++) cout << a[i] << " ";
  cout << "]\n";
}
void debugv(vector<int>& v) {
  cout << "Vector: [ ";
  for (auto i = 0; i != v.size(); i++) cout << v[i] << " ";
  cout << "]\n";
}
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  if (a.first < b.first || (a.first == b.first && a.second >= b.second))
    return true;
  return false;
}
long long int k[100000 + 2];
pair<long long int, long long int> power[100000 + 2];
void Solve() {
  long long int n;
  cin >> n;
  long long int ans = 0, temp;
  for (auto i = 0; i != n; i++) {
    cin >> k[i];
    long long int ma = 0;
    for (auto j = 0; j != k[i]; j++) {
      long long int p;
      cin >> p;
      ma = max(ma, p + 1 - j);
    }
    power[i].first = ma, power[i].second = k[i];
  }
  sort(power, power + n, comp);
  temp = ans = power[0].first;
  for (auto i = 0; i != n; i++) {
    if (temp >= power[i].first) {
      temp += power[i].second;
    } else {
      ans += (power[i].first - temp);
      temp = power[i].first + power[i].second;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
