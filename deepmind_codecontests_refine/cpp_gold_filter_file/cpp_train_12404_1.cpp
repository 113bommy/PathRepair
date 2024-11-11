#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  clock_t beg = clock();
  int t = 1;
  while (t--) {
    int n, m, s;
    cin >> n >> m >> s;
    int mm[n], ee[m];
    for (int i = 0; i < n; i++) cin >> mm[i];
    for (int i = 0; i < m; i++) cin >> ee[i];
    sort(mm, mm + n);
    sort(ee, ee + m);
    int ss = s / mm[0];
    cerr << ss << " ";
    ss *= ee[m - 1];
    cerr << ss << " ";
    cout << max(s, ss + (s - (mm[0] * (s / mm[0])))) << "\n";
  }
  clock_t end = clock();
  fprintf(stderr, "\n%lf sec\n", (double)(end - beg) / (CLOCKS_PER_SEC));
  return 0;
}
