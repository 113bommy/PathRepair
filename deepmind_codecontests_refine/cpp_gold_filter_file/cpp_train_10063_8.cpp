#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
void dance() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  dance();
  int n, k;
  cin >> n >> k;
  vector<int> v(n), temp(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    temp[i] = v[i];
  }
  sort(((temp).begin()), ((temp).end()));
  for (int i = 0; i < n; i++) {
    if (mp[temp[i]] == 0) {
      mp[temp[i]] = i + 1;
    }
  }
  map<int, int> sign;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if ((v[a - 1] > v[b - 1])) {
      sign[a - 1]++;
    }
    if (v[b - 1] > v[a - 1]) {
      sign[b - 1]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = v[i];
    int mn = mp[v[i]] - 1;
    if (sign[i]) {
      if (mn == 0)
        cout << 0;
      else
        cout << mn - sign[i];
    } else
      cout << mn;
    cout << ' ';
  }
}
