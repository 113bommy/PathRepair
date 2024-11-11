#include <bits/stdc++.h>
using namespace std;
string Y = "YES\n";
string N = "NO\n";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    vector<long long> arrL;
    vector<long long> arrR;
    map<long long, long long> pos;
    map<long long, long long> arrType;
    for (long long x = 0; x < n; x++) {
      char a;
      cin >> a;
      long long b;
      cin >> b;
      if (a == 'L') {
        pos[b] = arrL.size();
        arrType[b] = 1;
        arrL.push_back(b);
      } else if (a == 'R') {
        pos[b] = arrR.size();
        arrType[b] = 2;
        arrR.push_back(b);
      } else {
        long long type = arrType[b];
        if (type == 1) {
          long long a = arrL.size() - pos[b] - 1;
          long long c = arrR.size() + pos[b];
          long long answer = min(a, c);
          cout << answer << '\n';
        } else {
          long long a = arrR.size() - pos[b] - 1;
          long long c = arrL.size() + pos[b];
          long long answer = min(a, c);
          cout << answer << '\n';
        }
      }
    }
  }
  return 0;
}
