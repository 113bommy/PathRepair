#include <bits/stdc++.h>
using namespace std;
int n, a, value;
int S[100010], P[100010];
priority_queue<int> Q;
queue<int> T;
int main() {
  cin >> n >> a;
  for (int i = 1; i <= n; i++) {
    cin >> S[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> P[i];
  }
  value = S[a] + P[1];
  int p = 2;
  while (p <= n && a != 1) {
    if (S[a - 1] + P[p] <= value) a--;
    p++;
  }
  cout << a << '\n';
  return 0;
}
