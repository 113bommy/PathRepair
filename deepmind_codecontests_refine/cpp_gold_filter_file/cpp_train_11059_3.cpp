#include <bits/stdc++.h>
using namespace std;
long long max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string str;
  while (n--) {
    cin >> str;
    long long k = str.length();
    vector<int> v;
    v.push_back(0);
    for (long long i = 0; i < k; i++) {
      if (str[i] == 'R') {
        v.push_back(i + 1);
      }
    }
    v.push_back(k + 1);
    long long ans = 0;
    k = v.size();
    for (long long i = 0; i < k - 1; i++) {
      ans = max(ans, v[i + 1] - v[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
