#include <bits/stdc++.h>
using namespace std;
const int N = 106;
string s1[N], s2[N], s3[N], s4[N];
int a[26][N], b[26][N], g1[26], g2[26], k1[26], k2[26];
int t[N], d1[N], d2[N], r[N], f[N];
bool cmp1(int x, int y) { return s1[x] < s1[y]; }
bool cmp2(int x, int y) { return s2[x] < s2[y]; }
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> s1[i];
    s3[i] = s1[i];
  }
  for (i = 0; i < n; i++) {
    cin >> s2[i];
    s4[i] = s2[i];
  }
  for (i = 0; i < n; i++) d1[i] = d2[i] = i;
  sort(d1, d1 + n, cmp1);
  sort(d2, d2 + n, cmp2);
  for (i = 0; i < n; i++) f[d1[i]] = i;
  sort(s1, s1 + n);
  sort(s2, s2 + n);
  for (i = 0; i < n; i++) {
    int id = s1[i][0] - 'A';
    a[id][k1[id]++] = i;
    id = s2[i][0] - 'A';
    b[id][k2[id]++] = i;
  }
  int j;
  for (i = 0; i < 26; i++) {
    if (k1[i] - g1[i] == k2[i] - g2[i]) {
      int d = k1[i] - g1[i];
      for (j = 0; j < d; j++) {
        t[a[i][j + g1[i]]] = b[i][j + g2[i]];
      }
      g1[i] += d;
      g2[i] += d;
    } else if (k1[i] - g1[i] < k2[i] - g2[i]) {
      int d = k1[i] - g1[i];
      for (j = 0; j < d; j++) {
        t[a[i][j + g1[i]]] = b[i][j + g2[i]];
      }
      g1[i] += d;
      g2[i] += d;
    } else {
      int z = (k1[i] - g1[i]) - (k2[i] - g2[i]);
      for (j = 0; j < i; j++) {
        while (k2[j] - g2[j] > k1[j] - g1[j] && z) {
          t[a[i][g1[i]++]] = b[j][g2[j]++];
          z--;
        }
      }
      int d = k2[i] - g2[i];
      for (j = 0; j < d; j++) {
        t[a[i][j + g1[i]]] = b[i][j + g2[i]];
      }
      g1[i] += d;
      g2[i] += d;
      z = (k1[i] - g1[i]) - (k2[i] - g2[i]);
      while (z) {
        for (j = i + 1; j < 26; j++) {
          while (k2[j] - g2[j] > k1[j] - g1[j] && z) {
            t[a[i][g1[i]++]] = b[j][g2[j]++];
            z--;
          }
        }
      }
    }
  }
  for (i = 0; i < n; i++) r[d1[i]] = d2[t[i]];
  for (i = 0; i < n - 1; i++) {
    int h = d1[i];
    cout << s3[h] << " " << s4[r[h]] << ", ";
  }
  int h = f[i];
  cout << s3[h] << " " << s4[r[h]];
  return 0;
}
