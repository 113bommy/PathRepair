#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
const long long mod = 998244353;
string s, a, b;
int k, n;
char tem[30], teminv[30];
char c = char('a' - 2);
void no() { cout << "NO" << '\n'; }
void yes() { cout << "YES" << '\n'; }
void calc() {
  yes();
  for (int i = (int)0; i != (int)k; i = i + 1) {
    if (tem[i] == c) {
      for (int j = (int)0; j != (int)k; j = j + 1) {
        if (teminv[j] != c) continue;
        teminv[j] = char('a' + i);
        tem[i] = char('a' + j);
        break;
      }
    }
    cout << tem[i];
  }
  cout << '\n';
  return;
}
bool calc1(int st) {
  if (st == n) {
    calc();
    return true;
  }
  if (tem[s[st] - 'a'] != c) {
    if (tem[s[st] - 'a'] < a[st])
      return false;
    else if (tem[s[st] - 'a'] == a[st])
      return calc1(st + 1);
    else {
      calc();
      return true;
    }
  }
  for (int j = (int)a[st] - 'a' + 1; j != (int)27; j = j + 1) {
    if (teminv[j] == c) {
      tem[s[st] - 'a'] = char('a' + j);
      teminv[j] = s[st];
      calc();
      return true;
    }
  }
  if (teminv[a[st] - 'a'] != c) {
    return false;
  }
  tem[s[st] - 'a'] = a[st];
  teminv[a[st] - 'a'] = s[st];
  if (calc1(st + 1)) {
    return true;
  } else {
    tem[s[st] - 'a'] = c;
    teminv[a[st] - 'a'] = c;
    return false;
  }
}
bool calc2(int st) {
  if (st == n) {
    calc();
    return true;
  }
  if (tem[s[st] - 'a'] != c) {
    if (tem[s[st] - 'a'] > b[st])
      return false;
    else if (tem[s[st] - 'a'] == b[st])
      return calc2(st + 1);
    else {
      calc();
      return true;
    }
  }
  for (int j = (int)0; j != (int)b[st] - 'a'; j = j + 1) {
    if (teminv[j] == c) {
      tem[s[st] - 'a'] = char('a' + j);
      teminv[j] = s[st];
      calc();
      return true;
    }
  }
  if (teminv[b[st] - 'a'] != c) {
    return false;
  }
  tem[s[st] - 'a'] = b[st];
  teminv[b[st] - 'a'] = s[st];
  if (calc2(st + 1)) {
    return true;
  } else {
    tem[s[st] - 'a'] = c;
    teminv[b[st] - 'a'] = c;
    return false;
  }
}
void solve() {
  cin >> k;
  cin >> s >> a >> b;
  n = (int)s.size();
  fill(tem, tem + k, c);
  fill(teminv, teminv + k, c);
  int ne = -1;
  for (int i = (int)0; i != (int)n; i = i + 1) {
    if (a[i] != b[i]) {
      ne = i;
      break;
    }
    if (tem[s[i] - 'a'] != c && tem[s[i] - 'a'] != a[i]) {
      no();
      return;
    }
    if (teminv[a[i] - 'a'] != c && teminv[a[i] - 'a'] != s[i]) {
      no();
      return;
    }
    tem[s[i] - 'a'] = a[i];
    teminv[a[i] - 'a'] = s[i];
  };
  ;
  ;
  if (ne == -1) {
    calc();
    return;
  }
  for (char x = a[ne]; x <= b[ne]; x++) {
    if (tem[s[ne] - 'a'] != c && tem[s[ne] - 'a'] != x) continue;
    if (teminv[x - 'a'] != c && teminv[x - 'a'] != s[ne]) continue;
    if (x == a[ne]) {
      bool pehle_se = tem[s[ne] - 'a'] != c;
      tem[s[ne] - 'a'] = x;
      teminv[x - 'a'] = s[ne];
      if (calc1(ne + 1)) {
        return;
      }
      if (!pehle_se) {
        tem[s[ne] - 'a'] = c;
        teminv[x - 'a'] = c;
      }
    } else if (x == b[ne]) {
      bool pehle_se = tem[s[ne] - 'a'] != c;
      tem[s[ne] - 'a'] = x;
      teminv[x - 'a'] = s[ne];
      if (calc2(ne + 1)) {
        return;
      }
      if (!pehle_se) {
        tem[s[ne] - 'a'] = c;
        teminv[x - 'a'] = c;
      }
    } else {
      tem[s[ne] - 'a'] = x;
      teminv[x - 'a'] = s[ne];
      calc();
      return;
    }
  }
  no();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
