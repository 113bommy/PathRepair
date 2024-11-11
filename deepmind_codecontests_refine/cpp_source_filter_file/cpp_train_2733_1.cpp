#include <bits/stdc++.h>
using namespace std;
int a[1010];
int n, cnt;
int ansx[1010], ansy[1010];
void swp(int x, int y) {
  cnt++;
  swap(a[x], a[y]);
  ansx[cnt] = x;
  ansy[cnt] = y;
  return;
}
int id[1010];
bool cmp(int x, int y) { return a[x] > a[y]; }
map<int, vector<int> > S;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    S[a[i]].push_back(i);
  }
  int Num = 0;
  for (map<int, vector<int> >::iterator it = S.begin(); it != S.end(); it++) {
    vector<int> vec = it->second;
    for (int i = 0; i < vec.size(); i++) a[vec[i]] = ++Num;
  }
  for (int i = 1; i <= n; i++) {
    int N = 0;
    for (int j = i + 1; j <= n; j++)
      if (a[j] < a[i]) id[++N] = j;
    sort(id + 1, id + N + 1, cmp);
    for (int j = 1; j <= N; j++) swp(i, id[j]);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ansx[i], ansy[i]);
  return 0;
}
