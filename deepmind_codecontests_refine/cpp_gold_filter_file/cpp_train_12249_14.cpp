#include <bits/stdc++.h>
using namespace std;
bool notprime[5000001] = {};
int first[5000001];
int prime[500000];
set<int> P;
void pre() {
  first[1] = 1;
  int cnt = 0;
  for (int i = 2; i <= 5000000; i++) {
    if (!notprime[i]) {
      first[i] = i;
      prime[cnt++] = i;
    }
    for (int j = 0; j < cnt && prime[j] * i <= 5000000; j++) {
      notprime[i * prime[j]] = 1;
      first[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    P.insert(prime[i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  pre();
  int i;
  for (i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int f = 0;
    int buf = x;
    while (x != 1) {
      if (P.find(first[x]) == P.end()) {
        f = 1;
        break;
      }
      x /= first[x];
    }
    if (!f) {
      printf("%d ", buf);
      x = buf;
      while (x != 1) {
        if (P.find(first[x]) != P.end()) P.erase(P.find(first[x]));
        x /= first[x];
      }
    } else {
      for (int j = buf + 1;; j++) {
        int y = j;
        int ff = 0;
        while (y != 1) {
          if (P.find(first[y]) == P.end()) {
            ff = 1;
            break;
          }
          y /= first[y];
        }
        if (!ff) {
          printf("%d ", j);
          y = j;
          while (y != 1) {
            if (P.find(first[y]) != P.end()) {
              P.erase(P.find(first[y]));
            }
            y /= first[y];
          }
          break;
        }
      }
      break;
    }
  }
  auto iter = P.begin();
  for (i = i + 1; i < n; i++) {
    printf("%d ", *iter);
    iter++;
  }
}
