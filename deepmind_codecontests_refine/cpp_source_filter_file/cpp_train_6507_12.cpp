#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b) { return a.size() < b.size(); }
int main() {
  ios_base::sync_with_stdio(false);
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  int mx = 0;
  int count = 1;
  vector<string> v;
  while (getline(cin, s)) {
    v.push_back(s);
    mx = max(mx, (int)s.length());
  }
  cout << string(mx + 2, '*') << '\n';
  long long r, l;
  for (int i = 0; i < v.size(); i++) {
    cout << "*";
    int n = mx - v[i].length();
    r = n / 2;
    l = n / 2;
    if (n % 2 == 0) {
      while (r--) cout << ' ';
      cout << v[i];
      while (l--) cout << ' ';
      cout << "*" << '\n';
    } else if (n % 2 != 0) {
      if (count % 2 != 0) {
        r += 1;
        while (r--) cout << ' ';
        cout << v[i];
        while (l--) cout << ' ';
        cout << "*" << '\n';
        count++;
      } else {
        l += 1;
        while (r--) cout << ' ';
        cout << v[i];
        while (l--) cout << ' ';
        cout << "*" << '\n';
        count++;
      }
    }
  }
  cout << string(mx + 2, '*') << '\n';
}
