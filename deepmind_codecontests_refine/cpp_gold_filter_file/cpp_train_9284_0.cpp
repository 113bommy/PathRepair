#include <bits/stdc++.h>
using namespace std;
const int twx = 3e5 + 100;
const int inf = 0x3f3f3f3f;
long long read() {
  long long sum = 0;
  long long flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      flag = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = ((sum * 10) + c - '0');
    c = getchar();
  }
  return sum * flag;
}
int t;
int a, b;
char x[twx];
vector<int> v;
int ca, cb, cc;
int len;
void add(int i) {
  if (i >= b * 2) {
    cc++;
  } else if (i >= a) {
    ca++;
  } else if (i >= b) {
    cb++;
  }
}
void sub(int i) {
  if (i >= b * 2) {
    cc--;
  } else if (i >= a) {
    ca--;
  } else if (i >= b) {
    cb--;
  }
}
void init() {
  t = read();
  while (t--) {
    a = read();
    b = read();
    scanf("%s", x);
    len = strlen(x);
    v = {0};
    for (int i = 0; i <= len - 1; i++) {
      if (x[i] == '.') {
        v.back()++;
      } else if (v.back()) {
        v.push_back(0);
      }
    }
    if (!v.back()) {
      v.pop_back();
    }
    ca = cb = cc = 0;
    for (int i : v) add(i);
    bool o = 0;
    for (int i : v) {
      sub(i);
      for (int j = 0; j + a <= i; j++) {
        add(j);
        add(i - (j + a));
        if (!cc && !cb && ca % 2 == 0) {
          o = 1;
        }
        sub(j);
        sub(i - (j + a));
      }
      add(i);
    }
    puts(o ? "YES" : "NO");
  }
}
void work() {}
void print() {}
int main() {
  init();
  return 0;
}
