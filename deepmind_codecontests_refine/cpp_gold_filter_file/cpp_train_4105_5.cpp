#include <bits/stdc++.h>
using namespace std;
namespace _sort {
struct _sort {
  void swap(int &a, int &b) { a ^= b, b ^= a, a ^= b; }
  void sort(int s[], int i, int j) {
    if (i >= j) return;
    int l = i - 1, r = j + 1, m = s[(l + r) >> 1];
    while (l < r) {
      while (s[++l] < m)
        ;
      while (s[--r] > m)
        ;
      if (l < r) swap(s[l], s[r]);
    }
    sort(s, i, r), sort(s, r + 1, j);
  }
} Sort;
}  // namespace _sort
namespace _bsearch {
struct _bsearch {
  bool check(int x) {}
  int bsearch(int l, int r) {
    int m;
    while (l + 1 < r) {
      m = (l + r) >> 1;
      if (check(m))
        r = m;
      else
        l = m;
    }
    return r;
  }
} Bsearch;
}  // namespace _bsearch
namespace add {
struct in_one {
  vector<int> ad(vector<int> &f) {
    vector<int> ad;
    ad.push_back(f[0]);
    for (int i = 1; i < f.size(); i++) {
      ad.push_back(ad[i - 1] + f[i]);
    }
    return ad;
  }
} One;
struct in_two {
  vector<vector<int> > ad(vector<vector<int> > &f, int N) {
    vector<vector<int> > ad;
    ad[0].push_back(f[0][0]);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == 0 && j == 0)
          ad[0].push_back(f[0][0]);
        else if (i == 0)
          ad[i].push_back(f[i][j] + ad[i][j - 1]);
        else if (j == 0)
          ad[i].push_back(f[i][j] + ad[i - 1][j]);
        else
          ad[i].push_back(f[i][j] + ad[i - 1][j] + ad[i][j - 1] -
                          ad[i - 1][j - 1]);
      }
    }
    return ad;
  }
} Two;
}  // namespace add
int main() {
  using namespace _sort;
  int N, a[1039], maxn = 0, maxm = -1;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    if (a[i] > maxn) maxn = a[i], maxm = i;
  }
  Sort.sort(a, 1, N);
  printf("%d %d", maxm, a[N - 1]);
}
