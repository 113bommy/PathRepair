#include <bits/stdc++.h>
using namespace std;
inline void wait(double seconds) {
  double endtime = clock() + (seconds * CLOCKS_PER_SEC);
  while (clock() < endtime) {
    ;
  }
}
template <class T>
inline T fastIn() {
  register char c = 0;
  register T a = 0;
  bool neg = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-') {
      neg = true;
    } else {
      a = (a * 10) + (c - '0');
    }
    c = getchar();
  }
  return neg ? -a : a;
}
int a, b, str_len;
string str;
inline void read() {
  a = fastIn<int>(), b = fastIn<int>();
  cin >> str;
  str_len = (int)(str).length();
}
char cc[][2] = {{+0, +1}, {+0, -1}, {-1, +0}, {+1, +0}};
char mm[] = {'U', 'D', 'L', 'R'};
inline int get(char cc) {
  for (int i = 0, j1 = 4; i < j1; ++i) {
    if (cc == mm[i]) return i;
  }
  return -1;
}
pair<int, int> pi[105];
inline void proc() {
  int sr = 0, sc = 0;
  pi[0] = make_pair(sr, sc);
  for (int i = 0, j1 = str_len; i < j1; ++i) {
    int const di = get(str[i]);
    sr = sr + cc[di][0], sc = sc + cc[di][1];
    pi[i + 1] = make_pair(sr, sc);
    if (sr == a && sc == b) {
      puts("Yes");
      return;
    }
  }
  if (sr == 0 && sc == 0) {
    puts("No");
    return;
  }
  for (int i = 0, j1 = str_len + 1; i < j1; ++i) {
    int sx = a - pi[i].first;
    int sy = b - pi[i].second;
    bool b = 1;
    if (sr == 0) {
      if (sx != 0)
        continue;
      else if (sy % sc == 0 && sy / sc >= 0) {
        puts("Yes");
        return;
      }
    } else if (sc == 0) {
      if (sy != 0)
        continue;
      else if (sx % sr == 0 && sx / sr >= 0) {
        puts("Yes");
        return;
      }
    } else if (sx % sr == 0 && sy % sc == 0)
      if (sx / sr == sy / sc && sx / sr >= 0) {
        puts("Yes");
        return;
      }
  }
  puts("No");
}
int main() {
  int kase = 1;
  for (int i = 0, j1 = kase; i < j1; ++i) {
    read();
    proc();
  }
  return 0;
}
