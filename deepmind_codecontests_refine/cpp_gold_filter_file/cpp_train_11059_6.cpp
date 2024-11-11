#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length();
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'R') v.push_back(i + 1);
    }
    if (v.size() == 0)
      cout << n + 1 << endl;
    else {
      long long int ini = 0;
      long long int dif = INT_MIN;
      for (long long int i = 0; i < v.size(); i++) {
        long long int df = v[i] - ini;
        if (df > dif) dif = df;
        ini = v[i];
      }
      long long int df = (n + 1) - ini;
      if (df > dif) dif = df;
      cout << dif << endl;
    }
  }
  return 0;
}
