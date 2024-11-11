#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans;
void doit(int p, int L, int R) {
  char x;
  if (L + 1 == R) {
    printf("? %d %d\n", L, R);
    fflush(stdout);
    scanf(" %c", &x);
    if (x == '>') {
      ans[p] = pair<int, int>(R, L);
    } else
      ans[p] = pair<int, int>(L, R);
    return;
  }
  if (L == R) {
    ans[p] = pair<int, int>(L, L);
    return;
  }
  int mid = (L + R) / 2;
  doit(2 * p, L, mid);
  doit(2 * p + 1, mid + 1, R);
  printf("? %d %d\n", ans[2 * p].first, ans[2 * p + 1].first);
  fflush(stdout);
  scanf(" %c", &x);
  if (x == '>') {
    ans[p].first = ans[2 * p + 1].first;
  } else
    ans[p].first = ans[2 * p].first;
  printf("? %d %d\n", ans[2 * p].second, ans[2 * p + 1].second);
  fflush(stdout);
  scanf(" %c", &x);
  if (x == '>') {
    ans[p].second = ans[2 * p].second;
  } else
    ans[p].second = ans[2 * p + 1].second;
}
int main() {
  int qt;
  scanf("%d", &qt);
  while (qt--) {
    int tam;
    scanf("%d", &tam);
    vector<pair<int, int> > q;
    char x;
    for (int i = 1; i + 1 <= tam; i += 2) {
      printf("? %d %d\n", i, i + 1);
      fflush(stdout);
      scanf(" %c", &x);
      if (x == '>') {
        q.push_back(pair<int, int>(i + 1, i));
      } else
        q.push_back(pair<int, int>(i, i + 1));
    }
    if (tam & 1) q.push_back(pair<int, int>(tam, tam));
    while (q.size() > 1) {
      vector<pair<int, int> > tmp;
      for (int i = 0; i + 1 < (int)q.size(); i += 2) {
        printf("? %d %d\n", q[i].first, q[i + 1].first);
        fflush(stdout);
        scanf(" %c", &x);
        pair<int, int> qwe;
        if (x == '>') {
          qwe.first = q[i + 1].first;
        } else
          qwe.first = q[i].first;
        printf("? %d %d\n", q[i].second, q[i + 1].second);
        fflush(stdout);
        scanf(" %c", &x);
        if (x == '>') {
          qwe.second = q[i].second;
        } else
          qwe.second = q[i + 1].second;
        tmp.push_back(qwe);
      }
      if (int(q.size()) & 1) tmp.push_back(q.back());
      q = tmp;
    }
    printf("! %d %d\n", q[0].first, q[0].second);
    fflush(stdout);
  }
}
