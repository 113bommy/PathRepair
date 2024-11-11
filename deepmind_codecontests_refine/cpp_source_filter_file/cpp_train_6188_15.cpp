#include <bits/stdc++.h>
using lli = long long int;
using namespace std;
bool isprime(lli n);
lli gcd(lli a, lli b);
lli lcm(lli n, lli m);
lli fact(lli n);
double dgr(double a);
int fixMod(int a, int b);
long long ncr(int n, int r);
void fast();
lli maxSubArraySum(lli a[], lli size);
string infix2postfix(const string exp);
lli compute(lli h, lli n, int cur);
class PriorityQueue;
lli const L = 0;
lli cnt = 0;
int main() {
  fast();
  lli n, a, b, w;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> w;
    cout << ((w % b) * (a % b)) % b << ' ';
  }
}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
