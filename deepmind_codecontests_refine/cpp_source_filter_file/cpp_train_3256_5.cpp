#include <bits/stdc++.h>
using namespace std;
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool prime[1000001];
  memset(prime, true, sizeof(prime));
  int n = 1000001;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<int> vec;
  for (int i = 2; i <= 1000000; i++) {
    if (prime[i]) vec.push_back(i);
  }
  int x;
  cin >> x;
  while (x--) {
    int n;
    cin >> n;
    int y = sqrt(n);
    auto x1 = upper_bound(vec.begin(), vec.end(), y);
    auto x2 = upper_bound(vec.begin(), vec.end(), n);
    int v1, v2;
    if (x1 == vec.end()) {
      v1 = vec.size() + 1;
    } else {
      v1 = x1 - vec.begin();
    }
    if (x2 == vec.end()) {
      v2 = vec.size() + 1;
    } else {
      v2 = x2 - vec.begin();
    }
    cout << v2 - v1 + 1 << "\n";
  }
}
