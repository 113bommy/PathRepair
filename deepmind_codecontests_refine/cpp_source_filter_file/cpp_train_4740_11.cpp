#include <bits/stdc++.h>
using namespace std;
void numgen(vector<string> &v, string &s) {
  if (s.length() == 4) {
    v.push_back(s);
    return;
  }
  int p1 = s[0] - '0';
  int p2 = -1, p3 = -1;
  if (s.length() >= 2) {
    p2 = s[1] - '0';
  }
  if (s.length() == 3) {
    p3 = s[2] - '0';
  }
  for (int i = 0; i <= 9; i++) {
    if (i == p1 || i == p2 || i == p3) {
      continue;
    }
    char a = '0';
    a = (char)a + i;
    s.push_back(a);
    numgen(v, s);
    s.pop_back();
  }
}
bool chk(string &s, pair<string, pair<int, int> > &pp) {
  string str = pp.first;
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int uy = s[i] - '0';
    int uv = str[i] - '0';
    if (uy == uv) {
      cnt++;
    }
  }
  if (cnt == pp.second.first) {
    int val = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) {
          continue;
        }
        int y = s[i] - '0';
        int yy = str[j] - '0';
        if (y == yy) {
          val++;
        }
      }
    }
    if (val == pp.second.second) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<string> v;
  for (int i = 0; i <= 9; i++) {
    string s;
    char a = '0';
    a = (char)a + i;
    s.push_back(a);
    numgen(v, s);
  }
  int n;
  cin >> n;
  vector<pair<string, pair<int, int> > > vp(n);
  for (int i = 0; i < n; i++) {
    cin >> vp[i].first >> vp[i].second.first >> vp[i].second.second;
  }
  vector<string> ans;
  for (int i = 0; i < v.size(); i++) {
    int f = 0;
    for (int j = 0; j < n; j++) {
      if (chk(v[i], vp[j]) == false) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      ans.push_back(v[i]);
    }
  }
  if (ans.size() > 1) {
    cout << "Need More Data\n";
  } else if (ans.size() == 0) {
    cout << "Incorrect Data\n";
  } else {
    cout << ans[0] << "\n";
  }
}
