#include <bits/stdc++.h>
using namespace std;
struct second {
  char a[2][2];
};
vector<second> st;
vector<second>::iterator it;
bool equals(second s1, second s2) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (s1.a[i][j] != s2.a[i][j]) return false;
    }
  }
  return true;
}
void rec(int c, second s1) {
  st.push_back(s1);
  if (c == 4) return;
  int x, y;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (s1.a[i][j] == 'X') {
        x = i;
        y = j;
      }
    }
  }
  if (x == 0 && y == 0) {
    second _s1, _s2;
    _s1 = s1;
    _s2 = s1;
    swap(_s1.a[0][0], _s1.a[0][1]);
    swap(_s2.a[0][0], _s2.a[1][0]);
    rec(c + 1, _s1);
    rec(c + 1, _s2);
  } else if (x == 0 && y == 1) {
    second _s1, _s2;
    _s1 = s1;
    _s2 = s1;
    swap(_s1.a[0][1], _s1.a[0][0]);
    swap(_s2.a[0][1], _s2.a[1][1]);
    rec(c + 1, _s1);
    rec(c + 1, _s2);
  } else if (x == 1 && y == 0) {
    second _s1, _s2;
    _s1 = s1;
    _s2 = s1;
    swap(_s1.a[1][0], _s1.a[0][0]);
    swap(_s2.a[1][0], _s2.a[1][1]);
    rec(c + 1, _s1);
    rec(c + 1, _s2);
  } else {
    second _s1, _s2;
    _s1 = s1;
    _s2 = s1;
    swap(_s1.a[1][1], _s1.a[0][1]);
    swap(_s2.a[1][1], _s2.a[1][0]);
    rec(c + 1, _s1);
    rec(c + 1, _s2);
  }
}
int main() {
  second s1, s2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> s1.a[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> s2.a[i][j];
    }
  }
  rec(0, s1);
  for (it = st.begin(); it != st.end(); it++) {
    if (equals(*it, s2)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
