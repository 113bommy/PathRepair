#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
pair<int, int> mas[10];
vector<pair<int, int> > aaa;
pair<int, int> bbb[10];
int best = 0;
int main() {
  srand(time(0));
  int n, r;
  scanf("%d %d", &n, &r);
  int maxdist = r * r;
  for (int x = -r; x <= r; x++) {
    for (int y = -r; y <= r; y++) {
      if (x * x + y * y <= maxdist) aaa.push_back(make_pair(x, y));
    }
  }
  int len = (int)(aaa).size();
  int perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  while (clock() * 1e-3 < 0.7) {
    random_shuffle(aaa.begin(), aaa.end());
    for (int i = 0; i < n; i++) {
      int rnd = rand() % len;
      mas[i] = aaa[rnd];
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        cur +=
            (mas[i].first - mas[j].first) * (mas[i].first - mas[j].first) +
            (mas[i].second - mas[j].second) * (mas[i].second - mas[j].second);
      }
    }
    for (int x = 0; x < 3; x++) {
      random_shuffle(perm, perm + n);
      while (true) {
        int maxi = cur;
        for (int i = 0; i < n; i++) {
          int idx = perm[i];
          int s = 0;
          for (int k = 0; k < n; k++)
            s += (mas[idx].first - mas[k].first) *
                     (mas[idx].first - mas[k].first) +
                 (mas[idx].second - mas[k].second) *
                     (mas[idx].second - mas[k].second);
          int news = s;
          int xx = mas[idx].first, yy = mas[idx].second;
          for (int j = 0; j < len; j++) {
            int c = 0;
            for (int k = 0; k < n; k++)
              if (k != idx)
                c += (aaa[j].first - mas[k].first) *
                         (aaa[j].first - mas[k].first) +
                     (aaa[j].second - mas[k].second) *
                         (aaa[j].second - mas[k].second);
            if (c > news) {
              news = c;
              xx = aaa[j].first;
              yy = aaa[j].second;
            }
          }
          maxi += (news - s);
          mas[idx].first = xx;
          mas[idx].second = yy;
        }
        if (maxi > cur)
          cur = maxi;
        else
          break;
      }
    }
    if (cur > best) {
      best = cur;
      for (int i = 0; i < n; i++) bbb[i] = mas[i];
    }
  }
  printf("%d\n", best);
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", bbb[i].first, bbb[i].second);
  }
  return 0;
}
