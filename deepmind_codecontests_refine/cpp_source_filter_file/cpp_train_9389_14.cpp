#include <bits/stdc++.h>
inline int leq(int a1, int a2, int b1, int b2) {
  return a1 < b1 || a1 == b1 && a2 <= b2;
}
inline int leq(int a1, int a2, int a3, int b1, int b2, int b3) {
  return a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3);
}
void radixPass(int a[], int b[], int r[], int n, int K) {
  int* c = new int[K + 1];
  for (int i = 0; i <= K; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[r[a[i]]]++;
  for (int i = 0, sum = 0; i <= K; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
  delete[] c;
}
void suffixArray(int s[], int SA[], int n, int K) {
  int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
  int* s12 = new int[n02 + 3];
  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
  int* SA12 = new int[n02 + 3];
  SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
  int* s0 = new int[n0];
  int* SA0 = new int[n0];
  for (int i = 0, j = 0; i < n + (n0 - n1); i++)
    if (i % 3 != 0) s12[j++] = i;
  radixPass(s12, SA12, s + 2, n02, K);
  radixPass(SA12, s12, s + 1, n02, K);
  radixPass(s12, SA12, s, n02, K);
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int i = 0; i < n02; i++) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      name++;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    if (SA12[i] % 3 == 1)
      s12[SA12[i] / 3] = name;
    else
      s12[SA12[i] / 3 + n0] = name;
  }
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
  } else
    for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
  for (int i = 0, j = 0; i < n02; i++)
    if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
  radixPass(s0, SA0, s, n0, K);
  for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
    int i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    int j = SA0[p];
    if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                     : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                           s[j + 1], s12[j / 3 + n0])) {
      SA[k] = i;
      t++;
      if (t == n02)
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
    } else {
      SA[k] = j;
      p++;
      if (p == n0)
        for (k++; t < n02; t++, k++)
          SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    }
  }
  delete[] s12;
  delete[] SA12;
  delete[] SA0;
  delete[] s0;
}
void GetHeight(int s[], int SA[], int height[], int n) {
  int* rank = new int[n];
  for (int i = 0; i < n; i++) rank[SA[i]] = i;
  height[n - 1] = 0;
  for (int i = 0, h = 0; i < n; i++) {
    if (rank[i] == n - 1) continue;
    int j = SA[rank[i] + 1];
    while (s[i + h] == s[j + h]) h++;
    height[rank[i]] = h;
    if (h > 0) h--;
  }
  delete[] rank;
}
char buffer[201000];
int s[201000], h[201000], sa[201000];
int i, j, n, m;
long long int ans, delta, p[201000], temp;
int main() {
  scanf("%s", buffer);
  n = strlen(buffer);
  for (i = 0; i < n; i++) {
    s[i] = buffer[i] - 'a' + 1;
  }
  suffixArray(s, sa, n, 30);
  GetHeight(s, sa, h, n);
  delta = ans = 0;
  int last = 0;
  for (i = 0; i < n - 1; i++) {
    if (h[i] < last)
      j = h[i];
    else
      j = last;
    while (j < h[i]) {
      j++;
      p[j] = p[j - 1];
      p[j] += -i;
    }
    last = h[i];
    temp = i + 1;
    temp *= h[i];
    ans += temp;
    ans += p[j];
  }
  temp = n;
  temp *= (n - 1);
  temp /= 2;
  ans += temp + n;
  printf("%lld\n", ans);
  return 0;
}
