#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  std::vector<string> adj, noun, verb, res;
  adj.push_back("lios");
  adj.push_back("liala");
  noun.push_back("etr");
  noun.push_back("etra");
  verb.push_back("initis");
  verb.push_back("inites");
  long long m = -1, f = -1, c1 = 0, c2 = 0, c3 = 0;
  while (cin >> s) {
    long long n = s.length();
    string t;
    for (long long i = max((long long)0, n - 4); i < s.length(); ++i) {
      t += s[i];
    }
    if (t == adj[0]) {
      if (m == -1 && f == -1) {
        m = 1;
      } else if (f == 1) {
        cout << "NO";
        return 0;
      }
      c1++;
      if (c2 > 0 || c3 > 0) {
        cout << "NO";
        return 0;
      }
      continue;
    } else {
      string t;
      for (long long i = max((long long)0, n - 5); i < s.length(); ++i) {
        t += s[i];
      }
      if (t == adj[1]) {
        if (m == -1 && f == -1) {
          f = 1;
        } else if (m == 1) {
          cout << "NO";
          return 0;
        }
        c1++;
        if (c2 > 0 || c3 > 0) {
          cout << "NO";
          return 0;
        }
        continue;
      }
    }
    string t1;
    for (long long i = max((long long)0, n - 3); i < s.length(); ++i) {
      t1 += s[i];
    }
    if (t1 == noun[0]) {
      if (m == -1 && f == -1) {
        m = 1;
      } else if (f == 1) {
        cout << "NO";
        return 0;
      }
      c2++;
      if (c3 > 0 || c2 > 1) {
        cout << "NO";
        return 0;
      }
      continue;
    } else {
      string t1;
      for (long long i = max((long long)0, n - 4); i < s.length(); ++i) {
        t1 += s[i];
      }
      if (t1 == noun[1]) {
        if (m == -1 && f == -1) {
          f = 1;
        } else if (m == 1) {
          cout << "NO";
          return 0;
        }
        c2++;
        if (c3 > 0 || c2 > 1) {
          cout << "NO";
          return 0;
        }
        continue;
      }
    }
    string t2;
    for (long long i = max((long long)0, n - 6); i < s.length(); ++i) {
      t2 += s[i];
    }
    if (t2 == verb[0]) {
      if (m == -1 && f == -1) {
        m = 1;
      } else if (f == 1) {
        cout << "NO";
        return 0;
      }
      c3++;
      if (c1 > 0 && c2 == 0 || (c3 > 1 && c2 == 0)) {
        cout << "NO";
        return 0;
      }
    } else if (t2 == verb[1]) {
      if (m == -1 && f == -1) {
        f = 1;
      } else if (m == 1) {
        cout << "NO";
        return 0;
      }
      c3++;
      if ((c1 > 0 && c2 == 0) || (c3 > 1 && c2 == 0)) {
        cout << "NO";
        return 0;
      }
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (c3 == 0 && c2 == 0 && c1 > 1)
    cout << "NO";
  else
    cout << "YES";
}
