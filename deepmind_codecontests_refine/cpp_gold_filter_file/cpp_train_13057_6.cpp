#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
bool f(string s, long long int n) {
  for (long long int j = 0; j < 12 / n; j++) {
    long long int f = 0;
    for (long long int i = 0; i < 12; i += 12 / n) {
      if ((i + j) < 12 and s[i + j] != 'X') {
        f = 1;
        break;
      }
    }
    if (f == 0) return true;
  }
  return false;
}
int main() {
  long long int t;
  string s = "";
  cin >> t;
  while (t--) {
    s = "";
    cin >> s;
    v.clear();
    long long int ans = 0;
    for (long long int i = 1; i <= 12; i++) {
      if (12 % i == 0) {
        if (f(s, i)) {
          ans += 1;
          v.push_back(i);
          v.push_back(12 / i);
        }
      }
    }
    cout << ans;
    for (long long int i = 0; i < v.size(); i++) {
      cout << " " << v[i] << "x" << v[i + 1];
      i++;
    }
    cout << endl;
  }
}
