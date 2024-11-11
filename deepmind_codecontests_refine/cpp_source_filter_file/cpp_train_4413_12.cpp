#include <bits/stdc++.h>
using namespace std;
int n, s, t;
int d[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  cin >> s >> t;
  if (s > t) {
    swap(s, t);
  }
  int s1 = s, t1 = t;
  int Ans1 = 0, Ans2 = 0;
  while (s != t) {
    Ans1 += d[s];
    s++;
  }
  while (s != t) {
    Ans2 += d[t];
    t++;
    if (t == n + 1) {
      t = 1;
    }
  }
  cout << min(Ans1, Ans2);
  return 0;
}
