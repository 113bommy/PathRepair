#include <bits/stdc++.h>
using namespace std;
void gk() {}
int64_t mul(int64_t a, int64_t b) {
  return (a * b) % (int64_t)1000000007;
  ;
}
int64_t inv(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t x1, y1;
  int64_t g = inv(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
int64_t bexpo(int64_t a, int64_t n) {
  if (n <= 0) return 1;
  int64_t res = 1;
  while (n > 0) {
    if (n & 1) {
      res = (res * a) % 1000000007;
      ;
    }
    a = (a * a) % 1000000007;
    ;
    n >>= 1;
  }
  res %= 1000000007;
  ;
  return res;
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const int64_t sz = 1e3 + 3;
const int64_t sz2 = 3e4 + 50;
int64_t row[4] = {0, 1, 0, -1};
int64_t col[4] = {1, 0, -1, 0};
int64_t n, m;
void find() {
  int64_t n, k;
  cin >> n >> k;
  vector<string> ar(4 * n);
  for (string &s : ar) {
    cin >> s;
  }
  int64_t i = 0;
  for (i = 0; i < 4 * n; i += 4) {
    string s1 = ar[i];
    string s2 = ar[i + 1];
    string s3 = ar[i + 2];
    string s4 = ar[i + 3];
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    reverse(s4.begin(), s4.end());
    int64_t m = min({s1.size(), s2.size(), s3.size(), s4.size()});
    int64_t l = 0;
    int64_t f = 1;
    for (int64_t j = 0; j < m && l < k; j++) {
      if (s1[j] != s2[j] || s2[j] != s3[j] || s3[j] != s4[j]) {
        f = 0;
        break;
      }
      if (s1[j] == 'a' || s1[j] == 'e' || s1[j] == 'i' || s1[j] == 'o' ||
          s1[j] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
  }
  if (i >= 4 * n) {
    cout << "aaaa";
    return;
  }
  for (i = 0; i < 4 * n; i += 2) {
    string s1 = ar[i];
    string s2 = ar[i + 1];
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int64_t m = min(s1.size(), s2.size());
    int64_t l = 0;
    int64_t f = 1;
    for (int64_t j = 0; j < m && l < k; j++) {
      if (s1[j] != s2[j]) {
        f = 0;
        break;
      }
      if (s1[j] == 'a' || s1[j] == 'e' || s1[j] == 'i' || s1[j] == 'o' ||
          s1[j] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
  }
  if (i >= 4 * n) {
    cout << "aabb";
    return;
  }
  for (i = 0; i < 4 * n; i += 4) {
    string s1 = ar[i];
    string s2 = ar[i + 3];
    string s3 = ar[i + 1];
    string s4 = ar[i + 2];
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    reverse(s4.begin(), s4.end());
    int64_t l = 0;
    int64_t f = 1;
    int64_t m = min(s1.size(), s2.size());
    for (int64_t i = 0; i < m && l < k; i++) {
      if (s1[i] != s2[i]) {
        f = 0;
        break;
      }
      if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' ||
          s1[i] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
    f = 1;
    l = 0;
    m = min(s3.size(), s4.size());
    for (int64_t i = 0; i < m && l < k; i++) {
      if (s3[i] != s4[i]) {
        f = 0;
        break;
      }
      if (s3[i] == 'a' || s3[i] == 'e' || s3[i] == 'i' || s3[i] == 'o' ||
          s3[i] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
  }
  if (i >= 4 * n) {
    cout << "abba";
    return;
  }
  for (int64_t i = 0; i < 4 * n; i += 4) {
    string s1 = ar[i];
    string s2 = ar[i + 1];
    string s3 = ar[i + 2];
    string s4 = ar[i + 3];
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    reverse(s4.begin(), s4.end());
    int64_t m = min(s1.size(), s3.size());
    int64_t l = 0;
    int64_t f = 1;
    for (int64_t i = 0; i < m && l < k; i++) {
      if (s1[i] != s3[i]) {
        f = 0;
        break;
      }
      if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' ||
          s1[i] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
    f = 1;
    l = 0;
    m = min(s2.size(), s4.size());
    for (int64_t i = 0; i < m && l < k; i++) {
      if (s2[i] != s4[i]) {
        f = 0;
        break;
      }
      if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' ||
          s2[i] == 'u') {
        l++;
      }
    }
    if (!f || l < k) {
      break;
    }
  }
  if (i >= 4 * n) {
    cout << "abab";
    return;
  }
  cout << "NO";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);
  gk();
  int64_t t = 1;
  while (t--) {
    find();
  }
  return 0;
}
