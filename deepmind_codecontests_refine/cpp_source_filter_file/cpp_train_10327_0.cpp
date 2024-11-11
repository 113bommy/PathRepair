#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long f = 0; f < t; f++) {
    long long n, cnt = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<long long> v1, v2;
    for (long long i = 0; i < n; i++) {
      if (s[i] == t[i])
        ;
      else {
        cnt++;
        v1.push_back(s[i]);
        v2.push_back(s[i]);
      }
    }
    if (cnt > 2 || cnt == 1)
      cout << "No" << endl;
    else {
      if (!cnt)
        cout << "Yes" << endl;
      else if (v1[0] == v1[1] && v2[0] == v2[1])
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
