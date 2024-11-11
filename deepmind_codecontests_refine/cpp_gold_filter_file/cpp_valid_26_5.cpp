#include <bits/stdc++.h>
using namespace std;
bool prime(long long x) {
  if (x == 2) {
    return true;
  }
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i < sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void printv(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
string Y = "YES\n";
string N = "NO\n";
int rec(string s, int pos, int team1, int team2) {
  if (team1 < team2) {
    if (5 - (ceil((pos * 1.0) / 2)) < (team2 - team1)) {
      return pos;
    }
  } else {
    if (5 - (pos / 2) < (team1 - team2)) {
      return pos;
    }
  }
  if (pos == 10) {
    return 10;
  }
  int h = 10;
  if (pos % 2 == 0) {
    if (s[pos] == '1') {
      h = min(h, rec(s, pos + 1, team1 + 1, team2));
    } else if (s[pos] == '0') {
      h = min(h, rec(s, pos + 1, team1, team2));
    } else {
      int x =
          min(rec(s, pos + 1, team1 + 1, team2), rec(s, pos + 1, team1, team2));
      h = min(x, h);
    }
  } else {
    if (s[pos] == '1') {
      h = min(h, rec(s, pos + 1, team1, team2 + 1));
    } else if (s[pos] == '0') {
      h = min(h, rec(s, pos + 1, team1, team2));
    } else {
      int x =
          min(rec(s, pos + 1, team1, team2 + 1), rec(s, pos + 1, team1, team2));
      h = min(x, h);
    }
  }
  return h;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int pop = 0; pop < t; pop++) {
    string q;
    cin >> q;
    int c = rec(q, 0, 0, 0);
    cout << c << endl;
  }
  return 0;
}
