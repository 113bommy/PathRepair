#include <bits/stdc++.h>
using namespace std;
unsigned int v[100];
int main(int argc, char* argv[]) {
  unsigned int n, m;
  cin >> m >> n;
  for (unsigned int i = 0; i < n; ++i) {
    unsigned int k;
    cin >> k;
    for (unsigned int j = 0; j < k; ++j) {
      unsigned int x;
      cin >> x;
      v[x - 1] = 1;
    }
  }
  unsigned int r = accumulate(v, v + m, 0);
  cout << (r < m ? "NO\n" : "YES\n");
  return 0;
}
