#include <bits/stdc++.h>
using namespace std;
const int size = 2e5 + 10;
char a[size];
struct Letter {
  char c;
  int cnt;
};
int main() {
  scanf("%s", a);
  int len = int(strlen(a));
  vector<Letter> letters;
  for (int i = 0; i < len;) {
    Letter x;
    x.c = a[i];
    x.cnt = 0;
    for (int j = i; j < len; ++j) {
      if (a[j] == a[i]) {
        x.cnt++;
      } else {
        break;
      }
    }
    i += x.cnt;
    letters.push_back(x);
  }
  for (int i = 0; i < letters.size(); ++i) {
    if (letters[i].cnt > 2) {
      letters[i].cnt = 2;
    }
  }
  for (int i = 0; i < letters.size();) {
    int far = 0;
    for (int j = i; j < letters.size(); ++j) {
      if (letters[j].cnt == 2) {
        far++;
      } else {
        break;
      }
    }
    for (int j = 1; j < far; j += 2) {
      letters[i + j].cnt = 1;
    }
    i += far + 1;
  }
  for (int i = 0; i < letters.size(); ++i) {
    for (int j = 0; j < letters[i].cnt; ++j) {
      printf("%c", letters[i].c);
    }
  }
  return 0;
}
