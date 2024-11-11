#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int exp(long long int t, long long int x) {
  if (x == 0) return 1;
  if (x == 1) return t;
  if (x % 2 == 1) return (t * exp((t * t) % mod, x / 2)) % mod;
  if (x % 2 == 0) return exp((t * t) % mod, x / 2);
}
long long int gcd(long long int x, long long int y) {
  return x % y == 0 ? y : gcd(y, x % y);
}
long long int lcm(long long int x, long long int y) {
  return x * (y / gcd(x, y));
}
long long int bsum(long long int u, long long int b) {
  return u < b ? u : bsum(u / b, b) + u % b;
}
long long int prival(long long int u, long long int p) {
  int cn = 0;
  while (u % p == 0) {
    cn++;
    u = u / p;
  }
  return cn;
}
bool isprime(long long int x) {
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void YAY(void) { cout << "YES" << endl; }
void NAY(void) { cout << "NO" << endl; }
struct var {
  string id;
  string val;
  int def;
  int V1, V2;
  string OP;
} num[5111];
int temp[5111];
map<string, int> go;
string mmin, mmax;
int n, m;
int getbit(int loc, int b) {
  int i;
  int ret = 0;
  for (i = 1; i <= n; i++) {
    temp[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    if (num[i].def == 0) {
      ret += num[i].val[loc] - '0';
      temp[i] = num[i].val[loc] - '0';
    } else {
      int u, v;
      if (num[i].V1 == 0) {
        u = b;
      } else if (num[i].V1 != 0) {
        u = temp[num[i].V1];
      }
      if (num[i].V2 == 0) {
        v = b;
      } else if (num[i].V2 != 0) {
        v = temp[num[i].V2];
      }
      if (num[i].OP == "XOR") {
        ret += u ^ v;
        temp[i] = u ^ v;
      } else if (num[i].OP == "OR") {
        ret += u | v;
        temp[i] = u | v;
      } else if (num[i].OP == "AND") {
        ret += u & v;
        temp[i] = u & v;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    temp[i] = 0;
  }
  return ret;
}
int main(void) {
  int i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    string s, trash, num1;
    cin >> s >> trash >> num1;
    go[s] = i;
    num[i].id = s;
    if (num1[0] == '0' || num1[0] == '1') {
      num[i].def = 0;
      num[i].val = num1;
    } else {
      num[i].def = 1;
      if (num1[0] == '?') {
        num[i].V1 = 0;
      } else {
        num[i].V1 = go[num1];
      }
      string op, num2;
      cin >> op >> num2;
      num[i].OP = op;
      if (num2[0] == '?') {
        num[i].V2 = 0;
      } else {
        num[i].V2 = go[num2];
      }
    }
  }
  for (i = 0; i <= m - 1; i++) {
    int X = getbit(i, 0);
    int Y = getbit(i, 1);
    if (X > Y) {
      mmin.push_back('1');
      mmax.push_back('0');
    } else if (X < Y) {
      mmin.push_back('0');
      mmax.push_back('1');
    } else if (X == Y) {
      mmin.push_back('0');
      mmin.push_back('0');
    }
  }
  cout << mmin << endl << mmax;
}
