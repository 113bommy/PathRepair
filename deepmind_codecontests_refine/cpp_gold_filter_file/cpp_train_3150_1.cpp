#include <bits/stdc++.h>
using namespace std;
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x = 0, y = 0, z = 0;
    string s;
    cin >> s;
    stack<char> st;
    map<char, int> mp, p;
    map<int, char> q;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
      p[s[i]]++;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
      if (p[s[i]] >= 1) {
        st.push(s[i]);
        p[s[i]] = 0;
      }
    }
    int m;
    cin >> m;
    int a[m], b[m];
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      b[i] = a[i];
      if (a[i] != 0) z = 1;
    }
    if (z == 0) {
      while (mp[st.top()] < m) {
        st.pop();
      }
      while (m--) printf("%c", st.top());
      printf("\n");
    } else {
      while (1) {
        x = 0;
        for (int i = 0; i < m; i++) {
          if (a[i] == 0) {
            v.push_back(i);
          }
        }
        while (mp[st.top()] < v.size()) {
          st.pop();
        }
        for (int i = 0; i < v.size(); i++) {
          a[v[i]] = -1;
          q[v[i]] = st.top();
          for (int j = 0; j < m; j++) a[j] -= (abs)(j - v[i]);
        }
        st.pop();
        v.clear();
        if (y == 1) break;
        for (int i = 0; i < m; i++)
          if (a[i] > 0) x = 1;
        if (x == 0) {
          y = 1;
          continue;
        }
      }
      for (int i = 0; i < m; i++) printf("%c", q[i]);
      printf("\n");
    }
  }
}
