#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long> vv;
set<long long> st;
long long x, y, z;
string s, s1, s2, s3, s4, s5;
void memset_ll(long long a[], long long v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
void memset_s(char a[], char v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
int compare(const void* a, const void* b) {
  return (*(long long*)a - *(long long*)b);
}
void q_sort(long long a[], long long n) {
  qsort(a, n, sizeof(long long), compare);
}
static int compare1(const void* a, const void* b) {
  if (*(double*)a > *(double*)b)
    return 1;
  else if (*(double*)a < *(double*)b)
    return -1;
  else
    return 0;
}
void q_sort_d(double a[], long long n) {
  qsort(a, n, sizeof(double), compare1);
}
string trans_upper(string ss) {
  transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
  return ss;
}
long long power(long long a, long long b) {
  long long pow = 1;
  while (b) {
    if (b & 1) {
      pow = pow * a;
      --b;
    }
    a = a * a;
    b = b / 2;
  }
  return pow;
}
long long bsearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return bsearch(arr, l, mid - 1, x);
    return bsearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long fact(long long n) {
  long long f = 1, i;
  for (i = 1; i <= n; i++) f = f * i;
  return f;
}
long long is_prime(long long n) {
  long long i, j, k = 1;
  for (i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      k = 0;
      break;
    }
  }
  return k;
}
long long vow(char c) {
  long long k = 1;
  long long l = 0;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return k;
  else
    return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, l, p, q, n, m, o = 0, r, i, j, h, k, e = 0, d = 0, f = 0, g = 0;
  long long temp = 0, nl, np;
  double p1, p2 = 0.0, p3 = 0.0, p4, p5, p6, pp = 0.0, ppp;
  p1 = 3.1415926536;
  long long x1, x2, y1, y2, uu = 0, dd = 0, rr = 0, lll = 0;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '.') {
      p = i;
      g = 1;
      e++;
      break;
    }
  }
  if (g == 1) {
    if (s[p] == 'R') {
      l = p - 0;
      d += l;
    }
  }
  g = 0;
  for (i = n - 1; i >= 0; i--) {
    if (s[i] != '.') {
      p = i;
      g = 1;
      e++;
      break;
    }
  }
  if (g == 1) {
    if (s[p] == 'L') {
      l = n - 1 - p;
      d += l;
    }
  }
  if (g == 0) {
    cout << n;
    return 0;
  }
  for (i = 0; i < n;) {
    if (s[i] == 'R') {
      for (j = i + 1; j < n; j++) {
        if (s[j] == 'L') {
          t = j - i;
          if (t % 2 == 0) d++;
          i = j + 1;
          break;
        }
      }
      if (j == n) i = n;
    } else if (s[i] == 'L') {
      for (j = i + 1; j < n; j++) {
        if (s[j] == 'R') {
          t = j - i - 1;
          d += t;
          i = j;
          break;
        }
      }
      if (j == n) i = j;
    } else
      i++;
  }
  cout << d;
  return 0;
}
