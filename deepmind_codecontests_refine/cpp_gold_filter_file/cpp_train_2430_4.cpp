#include <bits/stdc++.h>
using namespace std;
string B, N;
long long c;
long long p10[1000010];
long long gp(long long x, long long p) {
  if (!p) return 1;
  long long q = gp(x, p / 2);
  q = (q * q) % c;
  if (p & 1) q = (q * x) % c;
  return q;
}
int main() {
  cin >> B >> N >> c;
  long long b = 0;
  for (int i = 0; i < B.size(); i++) b = (b * 10 + B[i] - '0') % c;
  p10[0] = b;
  for (int i = 1; i < N.size(); i++) p10[i] = gp(p10[i - 1], 10);
  N[N.size() - 1]--;
  for (int i = N.size() - 1; i >= 0; i--)
    if (N[i] < '0') {
      N[i] += 10;
      N[i - 1]--;
    } else
      break;
  long long ret = 1;
  for (int i = 0; i < N.size(); i++)
    ret = ret * gp(p10[N.size() - 1 - i], N[i] - '0') % c;
  ret = ret * (b + c - 1) % c;
  if (!ret) ret = c;
  cout << ret << endl;
}
