#include <bits/stdc++.h>
using namespace std;
long long M = 100001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  vector<char> v;
  for (long long i = 0; i < s.length(); i++) {
    v.push_back((char)s[i]);
  }
  long long c, m = M;
  c = count(v.begin(), v.end(), 'B');
  m = min(c, m);
  c = count(v.begin(), v.end(), 'u');
  m = min(c / 2, m);
  c = count(v.begin(), v.end(), 'l');
  m = min(c, m);
  c = count(v.begin(), v.end(), 'b');
  m = min(c, m);
  c = count(v.begin(), v.end(), 'a');
  m = min(c / 2, m);
  c = count(v.begin(), v.end(), 's');
  m = min(c, m);
  c = count(v.begin(), v.end(), 'r');
  m = min(c, m);
  cout << m;
}
