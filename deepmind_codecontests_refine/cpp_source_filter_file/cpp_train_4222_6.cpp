#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void Open() {}
pair<int, int> a[1000010];
int sta[1000010];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  Open();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x].first = i + 1;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x].second = i + 1;
  }
  sort(a, a + n, cmp);
  memset(sta, 0x3f, sizeof sta);
  int tail = 0;
  for (int i = 0; i < n; i++) {
    *(upper_bound(sta, sta + n, a[(i)].second)) = a[(i)].second;
  }
  cout << (lower_bound(sta, sta + n, INF) - sta) << endl;
  return 0;
}
