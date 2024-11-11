#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 2e5 + 100;
const long long LogN = 20;
const long long Inf = 2e15;
double eps = 1e-3;
long long md = 998244353;
long long dx[4] = {1, 0, 0, -1};
long long dy[4] = {0, 1, -1, 0};
long long gcdex(long long a, long long mod = md) {
  long long g = mod, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return x < 0 ? x + mod : x;
}
long long N;
vector<long long> lt;
vector<long long> rg;
long long getS(long long a, long long b, long long c) {
  cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
  long long t;
  cin >> t;
  return t;
}
long long getN(long long a, long long b, long long c) {
  cout << 2 << ' ' << a << ' ' << b << ' ' << c << endl;
  long long t;
  cin >> t;
  return t;
}
void calc() {
  for (int i = 3; i <= N; i++) {
    long long k = getN(1, 2, i);
    if (k == 1)
      lt.push_back(i);
    else
      rg.push_back(i);
  }
}
vector<long long> Ans;
long long d[MaxN];
void Sort(vector<long long>& Mt) {
  if ((Ans).size() == 0)
    Ans.push_back(1);
  else
    Ans.push_back(2);
  if ((Mt).size() == 0) {
    return;
  }
  long long t = Mt[0];
  for (long long a : Mt) {
    d[a] = getS(1, 2, a);
    if (d[a] > d[t]) t = a;
  }
  vector<long long> At;
  vector<long long> Bt;
  for (long long a : Mt) {
    if (a == t) continue;
    if (getN(1, t, a) == 1)
      At.push_back(a);
    else
      Bt.push_back(a);
  }
  sort(At.begin(), At.end(),
       [=](long long a, long long b) { return d[a] > d[b]; });
  sort(Bt.begin(), Bt.end(),
       [=](long long a, long long b) { return d[a] < d[b]; });
  for (long long a : Bt) Ans.push_back(a);
  Ans.push_back(t);
  for (long long a : At) Ans.push_back(a);
}
int main() {
  cin >> N;
  calc();
  Sort(rg);
  Sort(lt);
  cout << 0 << ' ';
  for (long long a : Ans) cout << a << ' ';
  cout << endl;
  return 0;
}
