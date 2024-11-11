#include <bits/stdc++.h>
using namespace std;
const int N = 300003;
const int M = 500005;
int n, m;
struct data {
  int x, y;
} e[M];
int b[N], use[M];
void read(int &x) { scanf("%d", &x); }
int main() {
  int T;
  read(T);
  while (T--) {
    read(n);
    read(m);
    for (int i = (1); i <= (n); i++) b[i] = 0;
    for (int i = (1); i <= (m); i++) use[i] = 0;
    int x, y, cnt = 0;
    for (int i = (1); i <= (m); i++) {
      read(x);
      read(y);
      e[i] = (data){x, y};
      if (!b[x] && !b[y]) b[x] = b[y] = use[i] = 1, cnt++;
    }
    if (cnt >= n) {
      puts("Matching");
      cnt = n;
      for (int i = (1); i <= (m); i++)
        if (use[i] && cnt) cnt--, printf("%d ", i);
    } else {
      puts("IndSet");
      cnt = n;
      for (int i = (1); i <= (3 * n); i++)
        if (!b[i] && cnt) cnt--, printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
