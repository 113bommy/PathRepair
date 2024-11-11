#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int x;
  cin >> x;
  return x;
}
long long n, k;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  long long Max = 0;
  long long ty = 1, num = 0;
  long long x;
  for (int i = (1); i <= (k); i++) {
    cin >> x;
    long long p = n / x;
    long long xx = p * x;
    if (xx > Max) {
      Max = xx;
      ty = i;
      num = p;
    }
  }
  cout << ty << " " << num << endl;
}
