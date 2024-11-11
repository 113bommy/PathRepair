#include <bits/stdc++.h>
using namespace std;
const int M1 = 3 * 1e5 + 1050;
const long long Q = 1e18 + 7;
int q[M1], st[M1], fi[M1], ind[M1];
int main() {
  srand(time(NULL));
  int n, M, T, l, r, c = 1;
  bool ok;
  scanf("%d%d%d", &n, &M, &T);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st[i] = ((s[0] - '0') * 10 + s[1] - '0') * 3600 +
            ((s[3] - '0') * 10 + s[4] - '0') * 60 +
            ((s[6] - '0') * 10 + s[7] - '0');
    fi[i] = st[i] + T - 1;
  }
  l = r = 0;
  ok = false;
  for (int i = 0; i < n; i++) {
    while (l < r && fi[q[l]] < st[i]) l++;
    if (r - l < M) {
      ind[i] = c++;
      q[r++] = i;
    } else {
      ind[i] = ind[q[r - 1]];
      q[r - 1] = i;
    }
    if (r - l == M) ok = true;
  }
  if (ok) {
    cout << c - 1 << endl;
    for (int i = 0; i < n; i++) cout << ind[i] << endl;
  } else
    cout << "No solution";
  return 0;
}
