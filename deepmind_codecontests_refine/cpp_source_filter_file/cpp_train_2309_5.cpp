#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  while (cin >> n) {
    long long x, sum = 0;
    map<long long, long long> mm, mk;
    mm.clear();
    mk.clear();
    for (long long i = 0; i < n; i++) {
      cin >> x;
      mm[x]++;
    }
    for (long long i = 1; i <= 150000; i++) {
      if (mm[i]) {
        if (!mk[i - 1] && i - 1 > 0) {
          mm[i]--;
          mk[i - 1]++;
        }
        if (mm[i] + mk[i] > 1 && i + 1 <= 150000) {
          mm[i]--;
          mk[i + 1]++;
        }
        if (mm[i]) mk[i]++;
      }
    }
    for (long long i = 1; i <= 150000; i++) {
      if (mk[i]) {
        sum++;
      }
    }
    cout << sum << endl;
  }
}
