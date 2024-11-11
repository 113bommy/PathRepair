#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[200500];
long long s[200500];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    long long s1 = 0;
    while (j >= 1 && t[i] - t[j] <= 1439) {
      s1 += s[j];
      j--;
    }
    long long s2 = 0;
    j = i - 1;
    while (j >= 1 && t[i] - t[j] <= 89) {
      s2 += s[j];
      j--;
    }
    long long r1 = max(0LL, 120 - s1);
    long long r2 = max(0LL, 50 - s2);
    if (r1 < r2) {
      if (r1 < 20)
        s[i] = r1;
      else if (r2 < 20)
        s[i] = r2;
      else
        s[i] = 20;
    } else {
      if (r2 < 20)
        s[i] = r2;
      else if (r1 < 20)
        s[i] = r1;
      else
        s[i] = 20;
    }
    cout << s[i] << endl;
  }
  return 0;
}
