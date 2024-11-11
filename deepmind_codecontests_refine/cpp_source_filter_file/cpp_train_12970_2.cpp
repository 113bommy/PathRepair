#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000 * 1000 * 1000 + 7;
const int mod = 1000 * 1000 * 1000 + 9;
const int num = 1000 * 1000 + 7;
const int N = 1000 + 7;
const double PI = 3.1415926535897932384626433832795;
int ux_x[5] = {0, 0, 1, -1};
int ux_y[5] = {1, -1, 0, 0};
int n, t, m, k;
long long a[num];
bool used[num];
long long ans = 0, ans1 = 0;
void solve() {
  string s;
  cin >> s;
  vector<int> v1, v2;
  for (int i = 0; i < s.length(); ++i) {
    int e = s[i] - '0';
    ans += e;
    if (e % 3 == 1) {
      v1.push_back(i);
    }
    if (e % 3 == 2) {
      v2.push_back(i);
    }
  }
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());
  if (ans % 3 == 0) {
    cout << s << endl;
    exit(0);
  }
  if (s.length() == 1) {
    cout << -1;
    exit(0);
  }
  if (ans % 3 == 1) {
    if (v1.size() == 0) {
      if (v2.size() < 1 || s.length() == 2) {
        cout << -1;
        exit(0);
      }
      s.erase(s.begin() + v2[0]);
      s.erase(s.begin() + v2[1]);
      if (s.length() == 1) {
        cout << s << endl;
        exit(0);
      }
      int e = 0;
      while (e < s.length() && s[e] == '0') e++;
      if (e == s.length()) {
        cout << -1;
        exit(0);
      }
      for (int i = e; i < s.length(); ++i) {
        cout << s[i];
      }
      exit(0);
    } else {
      if (v1[0] == 0 && s.length() > 2 && s[1] == '0' && s[2] == '0' &&
          v2.size() > 1) {
        s.erase(s.begin() + v2[0]);
        s.erase(s.begin() + v2[1]);
        if (s.length() == 1) {
          cout << s << endl;
          exit(0);
        }
        int e = 0;
        while (e < s.length() && s[e] == '0') e++;
        if (e == s.length()) {
          cout << 0;
          exit(0);
        }
        for (int i = e; i < s.length(); ++i) {
          cout << s[i];
        }
        exit(0);
      }
      s.erase(s.begin() + v1[0]);
      if (s.length() == 1) {
        cout << s << endl;
        exit(0);
      }
      int e = 0;
      while (e < s.length() && s[e] == '0') e++;
      if (e == s.length()) {
        cout << 0;
        exit(0);
      }
      for (int i = e; i < s.length(); ++i) {
        cout << s[i];
      }
      exit(0);
    }
  } else {
    if (v2.size() == 0) {
      if (v1.size() < 1 || s.length() == 2) {
        cout << -1;
        exit(0);
      }
      s.erase(s.begin() + v1[0]);
      s.erase(s.begin() + v1[1]);
      if (s.length() == 1) {
        cout << s << endl;
        exit(0);
      }
      int e = 0;
      while (e < s.length() && s[e] == '0') e++;
      if (e == s.length()) {
        cout << 0;
        exit(0);
      }
      for (int i = e; i < s.length(); ++i) {
        cout << s[i];
      }
      exit(0);
    } else {
      if (v2[0] == 0 && s.length() > 2 && s[1] == '0' && s[2] == '0' &&
          v1.size() > 1) {
        s.erase(s.begin() + v1[0]);
        s.erase(s.begin() + v1[1]);
        if (s.length() == 1) {
          cout << s << endl;
          exit(0);
        }
        int e = 0;
        while (e < s.length() && s[e] == '0') e++;
        if (e == s.length()) {
          cout << 0;
          exit(0);
        }
        for (int i = e; i < s.length(); ++i) {
          cout << s[i];
        }
        exit(0);
      }
      s.erase(s.begin() + v2[0]);
      int e = 0;
      if (s.length() == 1) {
        cout << s << endl;
        exit(0);
      }
      while (e < s.length() && s[e] == '0') e++;
      if (e == s.length()) {
        cout << -1;
        exit(0);
      }
      for (int i = e; i < s.length(); ++i) {
        cout << s[i];
      }
      exit(0);
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
