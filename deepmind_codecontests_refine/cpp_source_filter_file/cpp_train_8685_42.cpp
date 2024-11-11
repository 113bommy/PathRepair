#include <bits/stdc++.h>
using namespace std;
vector<long long> get(long long n) {
  vector<long long> ans;
  if (n == 1) {
    ans.push_back(1);
  } else if (n == 2) {
    ans.push_back(3);
    ans.push_back(4);
  } else if (n % 2) {
    for (long long i = 0; i < n - 1; i++) ans.push_back(1);
    ans.push_back((n - 2) / 2);
  } else {
    ans.push_back(2);
    for (long long i = 0; i < n - 2; i++) ans.push_back(1);
    ans.push_back((n + 1) / 2);
  }
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> f = get(n);
  vector<long long> g = get(m);
  for (long long i = 0; i < f.size(); i++) {
    for (long long j = 0; j < g.size(); j++) {
      cout << f[i] * g[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
