#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, string> > v;
void compare(string s1, string s2) {
  long long ans(0);
  for (long long i = 0; i < 3; i++) {
    for (long long j = i; j < s2.length(); j += 3) {
      if (s2[j] != s1[i]) {
        s2[j] = s1[i];
        ans++;
      }
    }
  }
  v.push_back({ans, s2});
}
int main() {
  long long n;
  string s, temp;
  cin >> n >> s;
  temp = s;
  compare("RGB", s);
  s = temp;
  compare("RBG", s);
  s = temp;
  compare("BRG", s);
  s = temp;
  compare("BGR", s);
  s = temp;
  compare("GRB", s);
  s = temp;
  compare("GBR", s);
  s = temp;
  sort(v.begin(), v.end());
  cout << v[0].first << endl << v[0].second;
  return 0;
}
