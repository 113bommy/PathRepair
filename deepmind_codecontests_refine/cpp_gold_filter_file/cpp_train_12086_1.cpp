#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
long long n, a[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n;
  for (int(i) = (0); ((i)) < ((n)); ((i))++) cin >> a[i];
  sort(a, a + n);
  long long t = 0;
  long long p = 0;
  long long s = 0;
  long long sum = 0;
  for (int(i) = (0); ((i)) < ((n)); ((i))++) {
    if (a[i] > s) {
      s = a[i];
      t += p;
      p = 0;
    }
    p++;
    if (t) {
      t--;
      sum++;
    }
  }
  cout << sum << endl;
}
