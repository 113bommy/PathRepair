#include <bits/stdc++.h>
using namespace std;
char s[400010];
int a[200];
vector<int> S;
vector<int> d, q;
int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) a[s[i]]++;
  int p = 0;
  for (int i = 0; i < 128; i++) {
    if (a[i] % 2) p++, a[i]--, S.push_back(i);
    if (a[i]) {
      d.push_back(i);
      q.push_back(a[i]);
    }
  }
  if (p == 0) {
    int cn = 0;
    for (int i = 0; i < 128; i++) {
      while (a[i]) s[cn++] = i, a[i] -= 2;
    }
    for (int i = 0; i < cn; i++) s[cn + i] = s[cn - i - 1];
    s[n] = '\0';
    printf("1\n%s\n", s);
  } else {
    int Min = n;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (i % 2 && n / i >= p && (n / i - p) % 2 == 0) Min = min(Min, n / i);
        if (n / i % 2 && i >= p && (i - p) % 2 == 0) Min = min(Min, i);
      }
    }
    printf("%d\n", Min);
    int L = n / Min;
    int pi = L / 2;
    int now = 0;
    for (int i = 0; i < Min; i++) {
      int x = pi + i * L;
      if (S.size() > i)
        s[x] = S[i];
      else {
        while (!q[now]) now++;
        s[x] = d[now];
        S.push_back(d[now]);
        S.push_back(d[now]);
        q[now] -= 2;
      }
      for (int i = 0; i < L / 2; i++) {
        while (!q[now]) now++;
        s[x - i - 1] = d[now];
        s[x + i + 1] = d[now];
        q[now] -= 2;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%c", s[i]);
      if (i % L == L - 1 && i != n - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
