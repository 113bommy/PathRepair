#include <bits/stdc++.h>
using namespace std;
int n, L, minID;
string s;
void fill(int id, string c) {
  for (int i = 0; i < c.size(); ++i) {
    L -= (s[id + i] == '?');
    s[id + i] = c[i];
  }
  minID = min(minID, id);
}
void query(char tp, string str) {
  cout << tp << " " << str << endl;
  cout.flush();
  if (tp == '?') {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0, t; i < k; ++i) cin >> t, fill(t - 1, str);
  } else if (tp == '!') {
    int tmp;
    cin >> tmp;
    assert(tmp);
  }
}
void solve() {
  query('?', "CH");
  query('?', "CO");
  query('?', "HC");
  query('?', "HO");
  if (L == n) {
    query('?', "CCC");
    if (minID < n) {
      fill(0, string(minID, 'O'));
    } else {
      query('?', "HHH");
      if (minID < n) {
        fill(0, string(minID, 'O'));
      } else {
        query('?', "OOO");
        if (minID == n) {
          query('?', "OOCC");
          if (minID == n) fill(0, "OOHH");
        }
        if (s[n - 1] == '?') {
          string t = s;
          t[n - 2] = t[n - 2] == '?' ? 'C' : t[n - 2];
          t[n - 1] = 'C';
          query('?', t);
          if (s[n - 1] == '?')
            fill(n - 2, (s[n - 2] == '?' ? "H" : string(1, t[n - 2])) + "H");
        }
      }
    }
  } else {
    int maxID = minID;
    while (maxID < n - 1 && s[maxID + 1] != '?') maxID++;
    for (int i = minID - 1; i >= 0; i--) {
      query('?', s.substr(i + 1, 1) + s.substr(minID, maxID - minID + 1));
      if (minID != i) {
        fill(0, string(i + 1, 'O'));
        break;
      }
    }
    int nextFilled;
    for (int i = maxID + 1; i < n; i++) {
      if (s[i] != '?') continue;
      nextFilled = i;
      while (nextFilled < n && s[nextFilled] == '?') nextFilled++;
      query('?', s.substr(0, i) + s[i - 1]);
      if (s[i] == '?') {
        if (nextFilled == n) {
          query('?', s.substr(0, i) + 'C');
          if (s[i] == '?') fill(i, "H");
          fill(i + 1, s.substr(n - i - 1, s[i]));
        } else
          fill(i, string(nextFilled - i, s[nextFilled]));
        i = nextFilled - 1;
      }
    }
  }
  query('!', s);
}
int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    s.clear();
    L = n;
    minID = n;
    s.resize(n, '?');
    solve();
  }
  return 0;
}
