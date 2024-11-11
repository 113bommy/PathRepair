#include <bits/stdc++.h>
int b[100001], s[100001];
using namespace std;
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  char c;
  int p, q, co = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    scanf("%c", &c);
    scanf("%d", &p);
    scanf("%d", &q);
    cin >> c >> p >> q;
    if (c == 'B')
      b[p] += q;
    else
      s[p] += q, st.insert(p);
  }
  int x = st.size();
  for (int i = 100000; i > 0 && co < t; i--)
    if (s[i] != 0 && x <= t) {
      printf("S %d %d\n", i, s[i]);
      co++;
    } else if (s[i] != 0)
      x--;
  co = 0;
  for (int i = 100000; i > 0 && co < t; i--)
    if (b[i] != 0) {
      printf("B %d %d\n", i, b[i]);
      co++;
    }
}
