#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T bpow(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int ts, kk = 1;
int n;
int fr[205];
int ls1[205];
int ls2[205];
int b[205];
int a[205];
int main() {
  int t, i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n + n; i++) {
    scanf("%d", &k);
    fr[k]++;
    a[i] = k;
  }
  int rs = 0;
  j = 0;
  k = 0;
  for (i = 0; i < 105; i++) {
    if (fr[i] >= 2) {
      if (j < n) {
        fr[i]--;
        ls1[j++] = i;
      }
      if (k < n) {
        fr[i]--;
        ls2[k++] = i;
      }
    } else if (fr[i] == 1) {
      if (j <= k) {
        fr[i]--;
        ls1[j++] = i;
      } else {
        fr[i]--;
        ls2[k++] = i;
      }
    }
  }
  for (i = 0; i < 105; i++) {
    while (fr[i] && j < n) {
      fr[i]--;
      ls1[j++] = i;
    }
  }
  for (i = 0; i < 105; i++) {
    while (fr[i] && k < n) {
      fr[i]--;
      ls2[k++] = i;
    }
  }
  set<int> st;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      st.insert(ls1[i] * 100 + ls2[j]);
    }
  }
  printf("%d\n", st.size());
  for (i = 0; i < n + n; i++) {
    for (j = 0; j < n; j++)
      if (ls1[j] == a[i]) {
        b[i] = 1;
        ls1[j] = -1;
        break;
      }
    if (j == n)
      for (j = 0; j < n; j++)
        if (ls2[j] == a[i]) {
          b[i] = 2;
          ls2[j] = -1;
          break;
        }
  }
  printf("%d", b[0]);
  for (i = 1; i < n + n; i++) printf(" %d", b[i]);
  return 0;
}
