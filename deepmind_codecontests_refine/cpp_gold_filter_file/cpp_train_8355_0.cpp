#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
void solve() {
  long long int n, x, y;
  cin >> n >> x >> y;
  long long int temp = n - 2;
  if (temp == 0) {
    cout << x << " " << y << '\n';
    return;
  }
  long long int dif = y - x;
  set<long long int> s;
  for (int i = 1; i <= sqrt(dif); i++) {
    if (dif % i == 0) {
      if (dif / i == i)
        s.insert(i);
      else {
        s.insert(i);
        s.insert(dif / i);
      }
    }
  }
  vector<long long int> v;
  if (s.find(temp + 1) != s.end()) {
    long long int jump = dif / (temp + 1);
    long long int temp2 = x;
    while (temp2 < y) {
      v.push_back(temp2);
      temp2 += jump;
    }
    v.push_back(y);
    long long int t = x - jump;
    while (t > 0 && v.size() < n) {
      v.push_back(t);
      t -= jump;
    }
    long long int k = y + jump;
    while (v.size() < n) {
      v.push_back(k);
      k += jump;
    }
  } else {
    long long int k;
    for (set<long long int>::iterator it = s.begin(); it != s.end(); it++) {
      if (*it < (temp + 1))
        k = *it;
      else
        break;
    }
    long long int jump = dif / k;
    long long int temp2 = x;
    while (temp2 < y) {
      v.push_back(temp2);
      temp2 += jump;
    }
    v.push_back(y);
    long long int t = x - jump;
    while (t > 0 && v.size() < n) {
      v.push_back(t);
      t -= jump;
    }
    long long int z = y + jump;
    while (v.size() < n) {
      v.push_back(z);
      z += jump;
    }
  }
  sort((v).begin(), (v).end());
  for (int i = 0; i < n; i++) cout << v[i] << " ";
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
