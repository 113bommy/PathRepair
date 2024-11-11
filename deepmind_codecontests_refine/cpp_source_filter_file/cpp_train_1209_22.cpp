#include <bits/stdc++.h>
int INP;
char BUF[1024 + 1], *inp = BUF;
using namespace std;
struct T {
  int l, r, d;
  T(int L = 0, int R = 0, int D = 0) : l(L), r(R), d(D) {}
};
inline bool cmp(const T& a, const T& b) {
  return a.l < b.l || a.l == b.l && a.r < b.r;
}
int a[222222], p[1111111], n, m, l, r, s;
long long S[222222];
vector<T> b[222222 / 500];
int main() {
  {
    {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    while (!(((INP) >= '0') && ((INP) <= '9'))) {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    n = INP - '0';
    {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    while ((((INP) >= '0') && ((INP) <= '9'))) {
      n = n * 10 + (INP - '0');
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
    }
  };
  {
    {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    while (!(((INP) >= '0') && ((INP) <= '9'))) {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    m = INP - '0';
    {
      if (!*inp) {
        fread(BUF, 1, 1024, stdin);
        inp = BUF;
      }
      INP = *inp++;
    };
    while ((((INP) >= '0') && ((INP) <= '9'))) {
      m = m * 10 + (INP - '0');
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
    }
  };
  for (int i = 0, x; i < n; i++) {
    {
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while (!(((INP) >= '0') && ((INP) <= '9'))) {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      x = INP - '0';
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while ((((INP) >= '0') && ((INP) <= '9'))) {
        x = x * 10 + (INP - '0');
        {
          if (!*inp) {
            fread(BUF, 1, 1024, stdin);
            inp = BUF;
          }
          INP = *inp++;
        };
      }
    };
    a[i] = x;
  }
  for (int i = 0, x, y; i < m; i++) {
    {
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while (!(((INP) >= '0') && ((INP) <= '9'))) {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      x = INP - '0';
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while ((((INP) >= '0') && ((INP) <= '9'))) {
        x = x * 10 + (INP - '0');
        {
          if (!*inp) {
            fread(BUF, 1, 1024, stdin);
            inp = BUF;
          }
          INP = *inp++;
        };
      }
    };
    {
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while (!(((INP) >= '0') && ((INP) <= '9'))) {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      y = INP - '0';
      {
        if (!*inp) {
          fread(BUF, 1, 1024, stdin);
          inp = BUF;
        }
        INP = *inp++;
      };
      while ((((INP) >= '0') && ((INP) <= '9'))) {
        y = y * 10 + (INP - '0');
        {
          if (!*inp) {
            fread(BUF, 1, 1024, stdin);
            inp = BUF;
          }
          INP = *inp++;
        };
      }
    };
    x--;
    b[(y - x) / 500].push_back(T(x, y, i));
  }
  for (int i = 0; i <= n / 500; i++)
    if (b[i].size()) {
      sort(b[i].begin(), b[i].end(), cmp);
      for (int j = 0; j < b[i].size(); j++) {
        T t = b[i][j];
        while (l > t.l)
          l--, s += (long long)(p[a[l]] * 2 + 1) * a[l], p[a[l]]++;
        while (l < t.l)
          p[a[l]]--, s -= (long long)(p[a[l]] * 2 + 1) * a[l], l++;
        while (r < t.r)
          s += (long long)(p[a[r]] * 2 + 1) * a[r], p[a[r]]++, r++;
        while (r > t.r)
          r--, p[a[r]]--, s -= (long long)(p[a[r]] * 2 + 1) * a[r];
        S[t.d] = s;
      }
    }
  for (int i = 0; i < m; i++) printf("%I64d\n", S[i]);
  return 0;
}
