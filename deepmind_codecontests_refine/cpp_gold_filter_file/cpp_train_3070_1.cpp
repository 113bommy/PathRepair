#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  string s, t, p;
  cin >> s >> t;
  p = s;
  int ncnt = 0;
  int N = s.length();
  for (int i = 0; i < N; i++) {
    if (s[i] != t[i]) ncnt++;
  }
  if (ncnt % 2 != 0) {
    printf("impossible\n");
  } else {
    int mid = ncnt / 2;
    int i = 0, c = 0;
    while (c < mid) {
      if (s[i] == t[i]) {
        p[i] = s[i];
      } else {
        c++;
        p[i] = s[i];
      }
      i++;
    }
    while (i < N) {
      if (s[i] == t[i]) {
        p[i] = s[i];
      } else {
        c++;
        p[i] = t[i];
      }
      i++;
    }
    cout << p << endl;
  }
  return 0;
}
