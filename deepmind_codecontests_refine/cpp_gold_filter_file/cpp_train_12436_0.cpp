#include <bits/stdc++.h>
using namespace std;
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
const int N = 200000 + 5;
int text[N], pat[N], a[N], b[N], lps[N], text_len, pat_len;
void cal_lps() {
  lps[0] = 0;
  int i = 1, indx = 0;
  while (i < pat_len) {
    if (pat[i] == pat[indx]) {
      lps[i] = indx + 1;
      i++, indx++;
    } else {
      if (indx != 0) {
        indx = lps[indx - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
int kmp() {
  cal_lps();
  int cnt = 0;
  int i = 0, j = 0;
  while (i < text_len) {
    if (pat[j] == text[i]) {
      i++, j++;
    }
    if (j == pat_len) {
      ++cnt;
      j = lps[j - 1];
    } else if (i < text_len && pat[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return cnt;
}
int main() {
  int n, w;
  while (scanf("%d%d", &n, &w) != EOF) {
    int k = -1, l = -1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < w; i++) scanf("%d", &b[i]);
    for (int i = 1; i < n; i++) text[++k] = a[i] - a[i - 1];
    for (int i = 1; i < w; i++) pat[++l] = b[i] - b[i - 1];
    text_len = k + 1;
    pat_len = l + 1;
    printf("%d\n", w == 1 ? n : kmp());
  }
  return 0;
}
