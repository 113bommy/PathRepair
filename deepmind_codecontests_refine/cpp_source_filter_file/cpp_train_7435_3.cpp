#include <bits/stdc++.h>
using namespace std;
long long n, x, cnt, mx;
bool bl;
vector<long long> v1, v2;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    v1.push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    cin >> x;
    v2.push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    bl = false;
    if (v2[i] == 1) {
      cnt -= 1;
    } else if (v1[i] * 2 >= v2[i]) {
      if (v1[i] % 2 == 0) {
        cnt += (v1[i] / 2) * (v1[i] / 2);
      } else {
        cnt += ((v1[i] / 2) + 1) * (v1[i] / 2);
      }
    } else {
      cnt -= 1;
    }
  }
  cout << cnt;
  cout << "\n";
  return 0;
}
