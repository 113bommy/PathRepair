#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > ip(n);
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    ;
    ip[i] = {t, i + 1};
  }
  sort(ip.begin(), ip.end());
  vector<long long> div1;
  vector<long long> div2;
  if (n & 1) {
    for (int i = 0; i < n - 1; i += 2) {
      div1.push_back(ip[i].second);
    }
    for (int i = 1; i < n - 1; i += 2) {
      div2.push_back(ip[i].second);
    }
    div1.push_back(ip[n - 1].second);
  } else {
    for (int i = 0; i < n; i += 2) {
      div1.push_back(ip[i].second);
    }
    for (int i = 1; i < n; i += 2) {
      div2.push_back(ip[i].second);
    }
  }
  cout << div1.size() << "\n";
  for (auto it : div1) cout << it << " ";
  cout << "\n";
  cout << div1.size() << "\n";
  for (auto it : div2) cout << it << " ";
  cout << "\n";
}
