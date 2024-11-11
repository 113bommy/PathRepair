#include <bits/stdc++.h>
using namespace std;
long long const mod = 1073741824;
long long m[5000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t, n, i, j, k = 0, cnt = 0, sum1 = 0, ccnt = 0, x, y, z, x1, y1 = 0,
                        z1, d, total = 0;
  cin >> n;
  long long a[n + 1], b[n + 1];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    m[b[i]]++;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (m[a[i] ^ b[i]]) {
        cnt++;
      }
    }
  }
  if (cnt & 1) {
    cout << "Koyomi" << endl;
  } else {
    cout << "Karen" << endl;
  }
  return 0;
}
