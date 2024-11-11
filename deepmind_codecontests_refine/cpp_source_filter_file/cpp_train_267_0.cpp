#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  long long d = v0;
  long long cnt = 1;
  long long i = 1;
  while (d < c) {
    d += min(v1, i * a + v0 - l);
    i++;
    cnt++;
  }
  cout << cnt;
}
