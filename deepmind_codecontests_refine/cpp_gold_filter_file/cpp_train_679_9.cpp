#include <bits/stdc++.h>
using namespace std;
long long int x, y;
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int gc = gcd(b % a, a);
  long long int temp;
  temp = x;
  x = y - (b / a) * temp;
  y = temp;
  return gc;
}
map<int, long long int> temp;
long long int fact[200005 * 10];
long long int inve[200005 * 10];
long long int val[200005 * 10];
long long int val1[200005 * 10];
long long int c(int x, int y) {
  long long int a;
  a = fact[x];
  a *= inve[x - y];
  a %= 1000000007;
  a *= inve[y];
  a %= 1000000007;
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int a, b, k, t;
  cin >> a >> b >> k >> t;
  int i, j;
  fact[0] = 1;
  inve[0] = 1;
  for (i = 1; i < 200005 * 2; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= 1000000007;
  }
  for (i = 1; i < 200005 * 2; i++) {
    gcd(1000000007, i);
    y = (y + 1000000007) % 1000000007;
    inve[i] = inve[i - 1] * y;
    inve[i] %= 1000000007;
  }
  int x, y;
  x = 2 * k + 1;
  x *= t;
  y = 1;
  for (i = t; i >= 0; i--) {
    temp[x - k * t] = (c(t, i) * y + 1000000007) % 1000000007;
    x -= 2 * k + 1;
    y *= -1;
  }
  long long int v;
  int z = 0;
  if (t % 2 == 0) {
    z = 1;
  } else
    z = -1;
  for (auto itr = temp.begin(); itr != temp.end(); itr++) {
    x = itr->first;
    for (i = 0; i <= 2 * t * k; i++) {
      y = i - t * k - x;
      if (y >= 0)
        v = c(y + t - 1, y) * z;
      else
        v = 0;
      v += 1000000007;
      v %= 1000000007;
      val[i] += v * itr->second;
      val[i] %= 1000000007;
    }
  }
  val1[0] = val[0];
  for (i = 1; i <= 2 * t * k; i++) {
    val1[i] = val1[i - 1] + val[i];
    val1[i] %= 1000000007;
  }
  x = b - a;
  long long int ans = 0;
  if (x >= 0) {
    for (i = 0; i <= 2 * t * k - x; i++) {
      ans += (val1[2 * t * k] - val1[i + x]) * val[i];
      ans %= 1000000007;
      ans += 1000000007;
      ans %= 1000000007;
    }
  } else {
    x *= -1;
    for (i = 0; i < x; i++) {
      ans += val[i] * val1[2 * t * k];
      ans %= 1000000007;
      ans += 1000000007;
      ans %= 1000000007;
    }
    for (i = x; i <= 2 * t * k; i++) {
      ans += val[i] * (val1[2 * t * k] - val1[i - x]);
      ans %= 1000000007;
      ans += 1000000007;
      ans %= 1000000007;
    }
  }
  cout << ans << endl;
}
