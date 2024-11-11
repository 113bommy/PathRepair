#include <bits/stdc++.h>
using namespace std;
template <class T>
T power(T a, T b) {
  T x;
  if (b == 0)
    x = 1;
  else
    x = a;
  for (size_t i = 1; i < b; i++) x *= a;
  return x;
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int n, m, a, b, c, ab, ba, x, y, z, avg, total, ans, sum;
long long int arr2[300001], arr3[100001], arr4[100001], arr5[100001];
char c1, c2;
vector<pair<string, long long int> > vec;
vector<long long int> v;
bool f, f1, f2, found;
string str, s1, s2, s3, s4;
map<long long int, long long int> mp, mp1;
set<int> seto;
double d, d1;
long long int x1, x2, y11, y2;
long long int mini = 10000000000, maxi = 0;
set<string> sets;
void rec(int n, string s) {
  if (n == 11) return;
  sets.insert(s);
  rec(n + 1, s + '4');
  rec(n + 1, s + '7');
}
int main() {
  rec(0, "");
  for (set<string>::iterator i = sets.begin(); i != sets.end(); i++) {
    string s = *i;
    if (!s.empty()) arr2[x++] = stoll(s);
  }
  sort(arr2, arr2 + x);
  cin >> n >> m;
  y = n;
  for (long long int i = 0; i < x; i++) {
    if (y <= arr2[i]) {
      sum += (min(arr2[i] - y, m - y) + 1) * arr2[i];
      y = arr2[i] + 1;
    }
    if (y > m) break;
  }
  cout << sum;
}
