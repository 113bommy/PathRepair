#include <bits/stdc++.h>
using namespace std;
int check(string tmp, int &r) {
  int len = tmp.size();
  if (tmp[len - 1] == 's' && tmp[len - 2] == 'o' && tmp[len - 3] == 'i' &&
      tmp[len - 4] == 'l') {
    r = 0;
    return 0;
  }
  if (tmp[len - 1] == 'r' && tmp[len - 2] == 't' && tmp[len - 3] == 'e') {
    r = 1;
    return 0;
  }
  if (tmp[len - 1] == 's' && tmp[len - 2] == 'i' && tmp[len - 3] == 't' &&
      tmp[len - 4] == 'i' && tmp[len - 5] == 'n' && tmp[len - 6] == 'i') {
    r = 2;
    return 0;
  }
  if (tmp[len - 1] == 'a' && tmp[len - 2] == 'l' && tmp[len - 3] == 'a' &&
      tmp[len - 4] == 'i' && tmp[len - 5] == 'l') {
    r = 0;
    return 1;
  }
  if (tmp[len - 1] == 'a' && tmp[len - 2] == 'r' && tmp[len - 3] == 't' &&
      tmp[len - 4] == 'e') {
    r = 1;
    return 1;
  }
  if (tmp[len - 1] == 's' && tmp[len - 2] == 'e' && tmp[len - 3] == 'i' &&
      tmp[len - 4] == 'n' && tmp[len - 5] == 'i' && tmp[len - 6] == 't') {
    r = 2;
    return 1;
  }
  return -1;
}
int main() {
  string s;
  bool flag = true;
  int k = 0, f;
  vector<int> v;
  while (cin >> s) {
    int shux;
    if (k == 0) {
      f = check(s, shux);
      v.push_back(shux);
      if (f == -1) {
        flag = false;
      }
    } else {
      if (f != check(s, shux)) {
        flag = false;
      }
      v.push_back(shux);
    }
    ++k;
  }
  if (flag) {
    bool ok = true;
    int len = v.size();
    int l = 0, now = 0;
    for (int i = 0; i < len; ++i) {
      if (v[i] < now) {
        ok = false;
        break;
      } else {
        now = v[i];
      }
      if (now == 1) l++;
    }
    if (ok && (len == 1 || l == 1)) {
      puts("YES");
    } else {
      puts("NO");
    }
  } else {
    puts("NO");
  }
  return 0;
}
