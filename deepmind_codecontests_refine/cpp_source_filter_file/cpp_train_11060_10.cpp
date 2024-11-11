#include <bits/stdc++.h>
using namespace std;
long long tra[100006], tra1[100006];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n;
    long long str[n + 4], s[n + 4];
    long long sum = 0, m, l, r, type, j = 0, rev = 0;
    long long num = n;
    num = num * 2;
    long long s1[n + 4];
    long long a = n / 2;
    long long b = n / 2;
    long long sum2 = 0, q = 0, w = 0;
    for (int i = 1; i < num / 2; i += 2) {
      sum += i;
      s[q++] = i;
      a--;
      if (a == 0) break;
      s[q++] = num - i;
      sum += (num - i);
      a--;
      if (a == 0) break;
    }
    for (int i = 2; i < num / 2; i += 2) {
      sum2 += i;
      s1[w++] = i;
      b--;
      if (b == 0) break;
      s1[w++] = num - i;
      sum2 += (num - i);
      b--;
      if (b == 0) break;
    }
    if (sum == sum2 && b == 0 && a == 0) {
      cout << "YES" << endl;
      for (int i = 0; i < q; i++) cout << s[i] << " ";
      for (int i = 0; i < w; i++) cout << s1[i] << " ";
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
