#include <bits/stdc++.h>
using namespace std;
long long res = 0;
long long gcd(long long a, long long b) {
  if (max(a, b) == 1 && min(a, b) == 1)
    return a;
  else {
    long long maxx = max(a, b);
    long long minx = min(a, b);
    res += maxx / minx;
    return gcd(minx, (maxx - 1) % minx + 1);
  }
}
long long cnk(long long n, long long k, long long mod) {
  if (k > n) return 0;
  double result = 1;
  long long lal = 0;
  for (long long lol = n; lol > n - k; lol--) {
    result *= lol;
    result /= (n - lol + 1);
  }
  return (long long)result;
}
vector<long long> graph[100000];
vector<long long> vec;
vector<long long> vecis;
vector<pair<pair<int, int>, int> > vec3;
long long log4(long long val) {
  long long lol = 1;
  long long ii = 0;
  if (val == 1) {
    return 1;
  }
  while (lol < val) {
    ii++;
    lol *= 4;
  }
  return ii;
}
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.first > b.first.first;
}
string tostr(long long a) {
  ostringstream out;
  out << a;
  return out.str();
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    return power(a, b / 2) * power(a, b / 2);
  } else
    return a * power(a, b - 1);
}
long long tobig(string str) {
  long long res = 0;
  for (long long lol = 0; lol < str.size(); lol++) {
    res += (str[lol] - 48) * power(10, str.size() - 1 - lol);
  }
  return res;
}
int t[1000000][26];
int h;
void update(int v, int tl, int tr, int newval, int pos, int sym) {
  if (tl == tr) {
    t[v][sym] = newval;
    return;
  } else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(v * 2, tl, tm, newval, pos, sym);
    } else {
      update(v * 2 + 1, tm + 1, tr, newval, pos, sym);
    }
  }
  t[v][sym] = t[v * 2][sym] + t[v * 2 + 1][sym];
}
int sum(long long v, int tl, int tr, int l, int r, int sym) {
  cout << v << "\n";
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v][sym];
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm), sym) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, sym);
}
long long su[100];
vector<bool> prime(200005, true);
vector<int> razn(100005);
long long cel(long long a, long long b) {
  long long res = a / b;
  if (a % b != 0) res++;
  return res;
}
long long mas[10000];
long long mas1[50], mas2[50];
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a + b < c - 2) {
    cout << -1;
    return 0;
  }
  long long res1 = 0, res2 = 0;
  long long kk = c;
  long long min1 = min(a - 1, c);
  c -= min1;
  res1 = a / (min1 + 1);
  res1 *= b / (c + 1);
  c = kk;
  long long min2 = min(b - 1, c);
  c -= min1;
  res2 = b / (min1 + 1);
  res2 *= a / (c + 1);
  cout << max(res1, res2);
  return 0;
}
