#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:136777216")
using namespace std;
int bits(int x) { return x == 0 ? 0 : 1 + bits(x & (x - 1)); }
const double PI = acos(-1.0);
const double eps = 1e-9;
const int INF = 1000000000;
string nextString() {
  char buf[1000000];
  scanf("%s", buf);
  return buf;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
vector<pair<int, int> > get_sort(int n) {
  vector<int> in(n);
  for (int(i) = 0; (i) < (n); (i)++) scanf("%d", &in[i]);
  vector<pair<int, int> > ans;
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n - 1); (j)++)
      if (in[j + 1] > in[j]) {
        swap(in[j + 1], in[j]);
        ans.push_back(make_pair(j, j + 1));
      }
  return ans;
}
int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> a(n), b(n);
  vector<pair<int, int> > res1 = get_sort(n), res2 = get_sort(n);
  reverse((res1).begin(), (res1).end());
  printf("%d\n", (int)(res1).size() + (int)(res2).size());
  for (int(i) = 0; (i) < ((int)(res2).size()); (i)++)
    printf("%d %d\n", res2[i].first + 1, res2[i].second + 1);
  for (int(i) = 0; (i) < ((int)(res1).size()); (i)++)
    printf("%d %d\n", res1[i].first + 1, res1[i].second + 1);
  return 0;
}
