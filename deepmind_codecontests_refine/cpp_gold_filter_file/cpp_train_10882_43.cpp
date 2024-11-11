#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int MAX_N = 1000100;
const long double eps = 1e-20;
const long double PI = 3.1415926535897932384626433832795;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long m;
  set<long long> s;
  vector<long long> ans;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
  }
  long long cnt = 0;
  for (int i = 1; i < MAX_N; i++) {
    if (s.find(i) == s.end() && cnt + i <= m) {
      ans.push_back(i);
      cnt += i;
    }
    if (cnt + i > m) {
      break;
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
