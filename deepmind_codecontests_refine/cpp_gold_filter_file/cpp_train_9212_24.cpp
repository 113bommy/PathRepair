#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1791791791;
vector<int> all;
int f(pair<int, int> a, pair<int, int> b, pair<int, int> c, vector<int> prm) {
  pair<int, int> ta, tb, tc;
  for (int flip = 0; flip < 8; flip++) {
    ta = a;
    tb = b;
    tc = c;
    if (flip & 1) swap(ta.first, ta.second);
    if (flip & 2) swap(tb.first, tb.second);
    if (flip & 4) swap(tc.first, tc.second);
    if (ta.second == tb.second && tb.second == tc.second &&
        ta.second == ta.first + tb.first + tc.first) {
      printf("%d\n", ta.second);
      for (int j = 0; j < ta.first; j++) {
        for (int i = 0; i < ta.second; i++) {
          printf("%c", prm[0]);
        }
        printf("\n");
      }
      for (int j = 0; j < tb.first; j++) {
        for (int i = 0; i < ta.second; i++) {
          printf("%c", prm[1]);
        }
        printf("\n");
      }
      for (int j = 0; j < tc.first; j++) {
        for (int i = 0; i < ta.second; i++) {
          printf("%c", prm[2]);
        }
        printf("\n");
      }
      exit(0);
    } else if (ta.second == tb.second + tc.second && tb.first == tc.first &&
               ta.second == ta.first + tb.first) {
      printf("%d\n", ta.second);
      for (int j = 0; j < ta.first; j++) {
        for (int i = 0; i < ta.second; i++) {
          printf("%c", prm[0]);
        }
        printf("\n");
      }
      for (int j = 0; j < tb.first; j++) {
        for (int i = 0; i < ta.second; i++) {
          if (i < tb.second)
            printf("%c", prm[1]);
          else
            printf("%c", prm[2]);
        }
        printf("\n");
      }
      exit(0);
    }
  }
}
int main() {
  vector<pair<int, int> > p;
  for (int i = 0; i < 3; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p.push_back(make_pair(a, b));
  }
  vector<int> pr({0, 1, 2});
  for (int i = 0; i < 3 * 2; i++) {
    next_permutation(pr.begin(), pr.end());
    vector<int> prm;
    for (auto a : pr) prm.push_back(a + 'A');
    f(p[pr[0]], p[pr[1]], p[pr[2]], prm);
  }
  printf("-1\n");
  return 0;
}
