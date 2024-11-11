#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
pair<long long, long long> bezout(long long a, long long b) {
  if (b == 1) return pair<long long, long long>(1, 1 - a);
  pair<long long, long long> sub = bezout(b, a % b);
  return pair<long long, long long>(sub.second,
                                    sub.first - (a / b) * sub.second);
}
long long inv(long long num) {
  pair<long long, long long> b = bezout(mod, num);
  b.second %= mod;
  if (b.second < 0) b.second += mod;
  return b.second;
}
int main() {
  int n;
  cin >> n;
  vector<vector<long long> > parts(n, vector<long long>(n, 0));
  parts[0] = vector<long long>(n, 1);
  long long part[n];
  part[0] = 1;
  for (int i = 1; i < n; i++) {
    long long sum = 1;
    for (int j = 1; j < n; j++) {
      parts[j][i] = parts[j][i - 1] * (j + 1) + parts[j - 1][i - 1];
      parts[j][i] %= mod;
      sum += parts[j][i];
    }
    part[i] = sum;
  }
  long long bin[n];
  bin[0] = 1;
  for (int i = 1; i < n; i++) {
    long long top = bin[i - 1] * (n + 1 - i);
    top %= mod;
    top *= inv(i);
    top %= mod;
    bin[i] = top;
  }
  long long sum = 1;
  for (int i = 1; i < n; i++) {
    sum += bin[i] * part[i - 1];
    sum %= mod;
  }
  cout << sum << endl;
}
