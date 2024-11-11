#include <bits/stdc++.h>
using namespace std;
long long nxt[30], n;
string s, t;
vector<long long> sol;
void do_op(long long x) {
  sol.push_back(x);
  string l = "", r = "";
  for (long i = 0; i < n - x; i++) {
    l += s[i];
  }
  for (long i = n - x; i < n; i++) {
    r += s[i];
  }
  reverse(r.begin(), r.end());
  s = r + l;
}
int main() {
  cin >> n >> s >> t;
  string a = s, b = t;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a != b) {
    cout << "-1" << endl;
    return 0;
  }
  for (long i = 0; i < n; i++) {
    if (!nxt[s[i] - 'a']) {
      nxt[s[i] - 'a'] = i + 1;
    }
  }
  for (long i = 0; i < n; i++) {
    long long letter = t[i] - 'a';
    long long gde = nxt[letter];
    do_op(n);
    do_op(gde - 1);
    do_op(1);
    for (long j = 0; j < 26; j++) {
      nxt[j] = 0;
    }
    for (long j = i + 1; j < n; j++) {
      if (!nxt[s[j] - 'a']) {
        nxt[s[j] - 'a'] = j + 1;
      }
    }
  }
  do_op(n);
  cout << sol.size() << endl;
  for (auto f : sol) {
    cout << f << " ";
  }
  cout << endl;
}
