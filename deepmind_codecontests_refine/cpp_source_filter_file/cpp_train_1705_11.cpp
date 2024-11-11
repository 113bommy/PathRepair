#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
int i, N;
int main() {
  cin >> N >> i;
  N = min(N, i);
  cout << N + 1 << endl;
  for (i = 0; i <= N; i++) cout << i << ' ' << i << endl;
}
