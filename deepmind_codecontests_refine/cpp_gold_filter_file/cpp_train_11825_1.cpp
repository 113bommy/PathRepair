#include <bits/stdc++.h>
using namespace std;
long long int Mmax(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int Mmin(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int nod(long long int a, long long int b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return Mmax(a, b);
}
long long int nok(long long int a, long long int b) {
  return a * b / nod(a, b);
}
bool IsPrime(long long int x) {
  if (x < 2) return false;
  long long int X = sqrt(x), i;
  for (i = 2; i <= X; i++)
    if (x % i == 0) return false;
  return true;
}
void hanoi(int n, int A, int C, int B) {
  if (n == 1) {
    cout << n << " " << A << " " << C << endl;
  } else {
    hanoi(n - 1, A, B, C);
    cout << n << " " << A << " " << C << endl;
    hanoi(n - 1, B, C, A);
  }
}
string pr2(string a, int d) {
  if (d == 0) return "0";
  string b;
  long long int sz = a.size(), i, prenos = 0;
  for (i = 0; i < sz; i++) {
    b[i] = a[i];
  }
  for (i = sz - 1; i > -1; i--) {
    a[i] = ((b[i] - '0') * d + prenos) % 10 + '0';
    prenos = ((b[i] - '0') * d + prenos) / 10;
  }
  if (prenos) a = char(prenos + '0') + a;
  return a;
}
string sum(string a, string b) {
  bool carry = false;
  long long int i, sz1, sz2, maxsz, minsz;
  string c, d;
  sz1 = a.size();
  sz2 = b.size();
  maxsz = max(sz1, sz2);
  minsz = min(sz1, sz2);
  while (sz1 < maxsz) {
    sz1++;
    a = '0' + a;
  }
  while (sz2 < maxsz) {
    sz2++;
    b = '0' + b;
  }
  for (i = maxsz - 1; i > -1; i--) {
    d = char((a[i] + b[i] - 96 + carry) % 10 + 48) + d;
    if (a[i] + b[i] - 96 + carry > 9)
      carry = true;
    else
      carry = false;
  }
  if (carry == true) d = char('1') + d;
  return d;
}
string pr(string a, string b) {
  string res = "0", p, p2;
  int sz = a.size(), x = 0;
  for (sz = a.size(); sz > 0; sz--, x++) {
    int d = a[sz - 1] - '0';
    a = a.erase(sz - 1, 1);
    p2 = pr2(b, d);
    p2 += p;
    res = sum(res, p2);
    p += "0";
  }
  return res;
}
bool vesokosna(long long int x) {
  return (x % 4 == 0 && x % 100 || x % 400 == 0);
}
long long int reverse(long long int x) {
  long long int mirror = 0;
  while (x) {
    mirror = mirror * 10 + x % 10;
    x /= 10;
  }
  return mirror;
}
long long int ost(string x, long long int k) {
  long long int num = 0, i, sz = x.size();
  for (i = 0; i < sz; i++) {
    num = num * 10;
    num += x[i] - '0';
    num %= k;
  }
  return num;
}
bool cmp(string a, string b) {
  int sz1 = a.size(), sz2 = b.size();
  if (sz1 < sz2) return true;
  if (sz1 > sz2) return false;
  if (a <= b) return true;
  if (a > b) return false;
}
vector<int> bits;
int main() {
  long long n;
  long long l, r, i;
  cin >> n >> l >> r;
  do {
    bits.push_back(n & 1);
    n >>= 1;
  } while (n >= 1);
  reverse(bits.begin(), bits.end());
  long long answer = 0;
  for (i = l; i <= r; i++) {
    int h = 0;
    long long j = i;
    while ((j & 1) == 0) {
      j >>= 1;
      h++;
    }
    answer += bits[h];
  }
  cout << answer << endl;
  return 0;
}
