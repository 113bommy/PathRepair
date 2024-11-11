#include <bits/stdc++.h>
using namespace std;
long long z;
long long to_dec(string s) {
  char rim[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  long long decc[7] = {1, 5, 10, 50, 100, 500, 1000};
  long long res = 0;
  for (long long i = 0; i < s.size(); i++) {
    long long tdig;
    for (long long j = 0; j < 7; j++) {
      if (rim[j] == s[i]) tdig = decc[j];
    }
    if (i < (long long)s.size() - 1 &&
        (s[i] == 'I' && s[i + 1] == 'V' || s[i] == 'I' && s[i + 1] == 'X' ||
         s[i] == 'X' && s[i + 1] == 'L' || s[i] == 'X' && s[i + 1] == 'C' ||
         s[i] == 'C' && s[i + 1] == 'D' || s[i] == 'C' && s[i + 1] == 'M')) {
      tdig *= (-1);
    }
    res += tdig;
  }
  return res;
}
vector<long long> decomp(long long n) {
  vector<long long> res;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}
bool IsDigit(char a) {
  if (a <= '9' && a >= '0')
    return 1;
  else
    return 0;
}
bool IsLetter(char a) {
  if ((a <= 'z' && a >= 'a') || (a <= 'Z' && a >= 'A'))
    return 1;
  else
    return 0;
}
signed F(long long a) {
  z = 1;
  if (a == 0) return 1;
  for (long long i = 1; i <= a; i++) {
    z = z * i;
  }
  return z;
}
bool IsPrime(long long a) {
  if (a <= 0) return 0;
  if (a == 1) return 0;
  if (a == 2) return 1;
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}
bool cmirt(long long n) {
  vector<long long> m;
  if (IsPrime(n)) return 0;
  long long l;
  m = decomp(n);
  long long sm1 = 0;
  z = n;
  while (z > 0) {
    sm1 += z % 10;
    z /= 10;
  }
  long long sm2 = 0;
  for (long long i = 0; i < m.size(); i++) {
    z = m[i];
    while (z > 0) {
      sm2 += z % 10;
      z /= 10;
    }
  }
  if (sm2 == sm1)
    return 1;
  else
    return 0;
}
vector<long long> srt(vector<long long>& v) {
  for (long long i = 0; i < v.size() - 1; i++) {
    for (long long j = i + 1; j < v.size(); j++) {
      if (v[i] > v[j]) swap(v[i], v[j]);
    }
  }
  return v;
}
long long kol_sosed(long long x, long long y, vector<string> v, char h,
                    long long n, long long m) {
  long long res;
  long long dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  long long dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  for (long long i = 0; i < 8; i++) {
    long long nx = x + dx[i];
    long long ny = y + dy[i];
    if (nx < 0) nx += n;
    if (ny < 0) ny += m;
    nx = nx % n;
    ny = ny % m;
    res += (v[nx][ny] == h);
  }
  return res;
}
vector<long long> srtl(vector<long long> v, long long mx) {
  vector<long long> pockets(mx + 1);
  for (long long i = 0; i < (long long)v.size(); i++) {
    pockets[v[i]]++;
  }
  long long k = 0;
  for (long long i = 0; i < (long long)pockets.size(); i++) {
    while (pockets[i] > 0) {
      v[k] = i;
      pockets[i]--;
      k++;
    }
  }
  return v;
}
vector<long long> maxr(vector<long long> v, long long n) {
  long long mx = -1e18;
  vector<long long> maxr(n, -1e18);
  for (long long i = n - 1; i >= 0; i--) {
    mx = max(mx, v[i]);
    maxr[i] = mx;
  }
  return maxr;
}
vector<long long> maxl(vector<long long> v, long long n) {
  long long mx = -1e18;
  vector<long long> maxl(n, -1e18);
  for (long long i = 0; i < n; i++) {
    mx = max(mx, v[i]);
    maxl[i] = mx;
  }
  return maxl;
}
string in_chr(long long n) {
  string s = "";
  while (n > 0) {
    s += (char)(n % 10) + 48;
    n /= 10;
  }
  return s;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a < b) {
    z = a;
    a = b;
    b = z;
  }
  if ((a - b) % 2 == 1) {
    cout << -1 << endl;
    return;
  }
  if (a == b) {
    if (a == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  } else {
    cout << 2 << endl;
  }
}
signed main() {
  long long u;
  cin >> u;
  while (u--) {
    solve();
  }
}
