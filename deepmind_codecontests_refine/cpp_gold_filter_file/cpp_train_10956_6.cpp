#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
int main() {
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, m;
    cin >> n >> m;
    long long int k = (1LL << m) - n;
    vector<long long int> vec;
    for (long long int i = 0; i < n; i++) {
      string s;
      cin >> s;
      long long int val = 0;
      for (char c : s) {
        if (c == '0') {
          val = val * 2;
        } else {
          val = val * 2 + 1;
        }
      }
      vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    long long int req = (k - 1) / 2;
    long long int low = 0;
    for (long long int i = 0; i < vec.size(); i++) {
      long long int val = vec[i];
      if (vec[i] <= req) {
        req++;
      } else {
        break;
      }
    }
    string s = "";
    long long int val = req;
    while (val > 0) {
      if (val % 2) {
        s += "1";
      } else {
        s += "0";
      }
      val = val / 2;
    }
    while (s.size() < m) s += "0";
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}
