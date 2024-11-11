#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long q, h, w, a;
  cin >> q;
  for (long long qq = 0; qq < q; ++qq) {
    cin >> h >> w;
    long long su1 = 0, su2 = 0;
    vector<long long> a1, a2, a3, a4;
    for (long long i = 0; i < h; ++i) {
      for (long long j = 0; j < w; ++j) {
        cin >> a;
        if (i == h / 2)
          a2.push_back(a);
        else if (i == h / 2 + 1)
          a3.push_back(a);
        else if (i == 0)
          a1.push_back(a);
        else if (i == h - 1)
          a4.push_back(a);
      }
    }
    for (long long i = 0; i < w; ++i) {
      su1 += abs(a1[i] - a4[i]);
      su2 += abs(a2[i] - a3[i]);
    }
    if (su1 < su2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
