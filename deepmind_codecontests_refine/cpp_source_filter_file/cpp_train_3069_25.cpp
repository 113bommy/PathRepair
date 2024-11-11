#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::vector<std::vector<std::vector<T>>> make_3d_vector(long long z,
                                                        long long y,
                                                        long long x,
                                                        T value = T{}) {
  return std::vector<std::vector<std::vector<T>>>(
      z, std::vector<std::vector<T>>(y, std::vector<T>(x, value)));
}
template <typename T>
std::vector<std::vector<T>> make_2d_vector(long long z, long long y,
                                           T value = T{}) {
  return std::vector<std::vector<T>>(z, std::vector<T>(y, value));
}
template <typename T>
std::vector<T> make_1d_vector(long long z, T value = T{}) {
  return std::vector<T>(z, value);
}
template <typename Templ1isPerfectSquare>
bool isPerfectSquare(Templ1isPerfectSquare n) {
  Templ1isPerfectSquare sq = sqrt(n);
  return ((sq * sq) == n);
}
long long powerll_modulo(long long a, long long n, long long mod) {
  long long res = 1;
  a = a % mod;
  while (n) {
    if (n % 2 == 1) {
      n--;
      res *= a;
      res = res % mod;
    }
    if (n > 0) {
      n /= 2;
      a = a * a;
      a %= mod;
    }
  }
  return res;
}
long long powerll(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2 == 1) {
      n--;
      res *= a;
    }
    if (n > 0) {
      n /= 2;
      a = a * a;
    }
  }
  return res;
}
string stringMultiplication(string a, string b) {
  vector<long long> v(a.size() + b.size() + 100, 0);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (long long i = 0; i < a.size(); i++) {
    for (long long j = 0; j < b.size(); j++) {
      v[i + j] += ((a[i] - '0') * (b[j] - '0'));
    }
  }
  for (long long i = 0; i < v.size() - 1; i++) {
    v[i + 1] += v[i] / 10;
    v[i] = v[i] % 10;
  }
  long long j = v.size() - 1;
  while (j >= 0 && v[j] == 0) {
    j--;
  }
  string res = "";
  for (; j >= 0; j--) {
    res += (char)(v[j] + '0');
  }
  if (res == "") res = "0";
  return res;
}
long long Ncr(long long n, long long m) {
  map<long long, long long> mp1;
  unordered_map<long long, long long> mp2;
  vector<long long> v1;
  vector<long long> v2;
  for (long long i = 1; i < n + 1; i++) {
    long long k = i;
    for (long long j = 2; j < sqrt(k) + 1; j++) {
      if (k % j == 0) {
        long long ct = 0;
        while (k % j == 0) {
          ct++;
          k /= j;
        }
        if (!mp1[j]) {
          v1.push_back(j);
        }
        mp1[j] += ct;
      }
    }
    if (k > 1) {
      if (mp1[k] == 0) {
        v1.push_back(k);
      }
      mp1[k]++;
    }
  }
  for (long long i = 1; i < m + 1; i++) {
    long long k = i;
    for (long long j = 2; j < sqrt(k) + 1; j++) {
      if (k % j == 0) {
        long long ct = 0;
        while (k % j == 0) {
          ct++;
          k /= j;
        }
        if (!mp2[j]) {
          v2.push_back(j);
        }
        mp2[j] += ct;
      }
    }
    if (k > 1) {
      if (mp2[k] == 0) {
        v2.push_back(k);
      }
      mp2[k]++;
    }
  }
  for (long long i = 1; i < n - m + 1; i++) {
    long long k = i;
    for (long long j = 2; j < sqrt(k) + 1; j++) {
      if (k % j == 0) {
        long long ct = 0;
        while (k % j == 0) {
          ct++;
          k /= j;
        }
        if (!mp2[j]) {
          v2.push_back(j);
        }
        mp2[j] += ct;
      }
    }
    if (mp2[k] == 0) {
      v2.push_back(k);
    }
    mp2[k]++;
  }
  long long num = 1, den = 1;
  for (long long i = 0; i < v1.size(); i++) {
    if (mp2[v1[i]] > mp1[v1[i]]) {
      mp2[v1[i]] -= mp1[v1[i]];
      mp1[v1[i]] = 0;
    } else {
      mp1[v1[i]] -= mp2[v1[i]];
      mp2[v1[i]] = 0;
    }
    num *= powerll(v1[i], mp1[v1[i]]);
  }
  for (long long i = 0; i < v2.size(); i++) {
    if (mp2[v2[i]] > mp1[v2[i]]) {
      mp2[v2[i]] -= mp1[v2[i]];
      mp1[v2[i]] = 0;
    } else {
      mp1[v2[i]] -= mp2[v2[i]];
      mp2[v2[i]] = 0;
    }
    den *= powerll(v2[i], mp2[v2[i]]);
  }
  return num / den;
}
long long white = 0, black = 0;
void addd(char c) {
  if (c >= 'A' && c <= 'Z') {
    if (c == 'Q')
      white += 8;
    else if (c == 'R')
      white += 5;
    else if (c == 'B')
      white += 3;
    else if (c == 'K')
      white += 3;
    else if (c == 'P')
      white += 1;
  } else {
    if (c == 'q')
      black += 8;
    else if (c == 'r')
      black += 5;
    else if (c == 'b')
      black += 3;
    else if (c == 'k')
      black += 3;
    else if (c == 'p')
      black += 1;
  }
}
void solve() {
  vector<string> v(8);
  for (auto &x : v) cin >> x;
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      addd(v[i][j]);
    }
  }
  if (white > black) {
    cout << "White";
  } else if (black > white) {
    cout << "Black";
  } else {
    cout << "Draw";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
}
