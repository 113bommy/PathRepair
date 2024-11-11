#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long x = n;
  vector<long long> v;
  while (n > 0) {
    long long temp = n % 10;
    n /= 10;
    v.push_back(temp);
  }
  std::map<long long, string> m;
  m.insert(pair<long long, string>(0, "zero"));
  m.insert(pair<long long, string>(1, "one"));
  m.insert(pair<long long, string>(2, "two"));
  m.insert(pair<long long, string>(3, "three"));
  m.insert(pair<long long, string>(4, "four"));
  m.insert(pair<long long, string>(5, "five"));
  m.insert(pair<long long, string>(6, "six"));
  m.insert(pair<long long, string>(7, "seven"));
  m.insert(pair<long long, string>(8, "eight"));
  m.insert(pair<long long, string>(9, "nine"));
  m.insert(pair<long long, string>(10, "ten"));
  m.insert(pair<long long, string>(11, "eleven"));
  m.insert(pair<long long, string>(12, "twelve"));
  m.insert(pair<long long, string>(13, "thirteen"));
  m.insert(pair<long long, string>(14, "fourteen"));
  m.insert(pair<long long, string>(15, "fifteen"));
  m.insert(pair<long long, string>(16, "sixteen"));
  m.insert(pair<long long, string>(17, "seventeen"));
  m.insert(pair<long long, string>(18, "eighteen"));
  m.insert(pair<long long, string>(19, "nineteen"));
  m.insert(pair<long long, string>(20, "twenty"));
  m.insert(pair<long long, string>(30, "thirty"));
  m.insert(pair<long long, string>(40, "forty"));
  m.insert(pair<long long, string>(50, "fifty"));
  m.insert(pair<long long, string>(60, "sixty"));
  m.insert(pair<long long, string>(70, "seventy"));
  m.insert(pair<long long, string>(80, "eighty"));
  m.insert(pair<long long, string>(90, "ninety"));
  if (x <= 20 || v[0] == 0) {
    cout << m[x] << '\n';
  } else {
    cout << m[v[1] * 10] << "-" << m[v[0]] << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
