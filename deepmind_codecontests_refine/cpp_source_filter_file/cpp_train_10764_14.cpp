#include <bits/stdc++.h>
using namespace std;
struct control_point {
  long long x;
  long long y;
  vector<int> lst;
};
struct circle {
  long long r;
  long long x;
  long long y;
};
long long numsimilar(vector<int> alist, vector<int> blist) {
  long long count = 0;
  int m, n;
  int i = 0, j = 0;
  m = alist.size();
  n = blist.size();
  while (i < m && j < n) {
    if (alist[i] < blist[j])
      i++;
    else if (blist[j] < alist[i])
      j++;
    else {
      count++;
      i++;
      j++;
    }
  }
  return m + n - 2 * count;
}
bool find_intersection(struct control_point p, struct circle c) {
  long long newx = p.x - c.x;
  long long newy = p.y - c.y;
  if (newx * newx + newy * newy < c.r * c.r) return true;
  return false;
}
void print_vec(vector<int> lst) {
  for (int i = 0; i < lst.size(); i++) printf("%d ", lst[i]);
  printf("\n");
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<control_point> nlist;
  vector<circle> clist;
  long long kx, ky, r;
  for (int i = 0; i < n; i++) {
    cin >> kx >> ky;
    struct control_point temp;
    temp.x = kx;
    temp.y = ky;
    nlist.push_back(temp);
  }
  for (int i = 0; i < m; i++) {
    cin >> r >> kx >> ky;
    struct circle temp;
    temp.x = kx;
    temp.y = ky;
    temp.r = r;
    clist.push_back(temp);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (find_intersection(nlist[i], clist[j])) nlist[i].lst.push_back(j);
  long long a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    cout << numsimilar(nlist[a - 1].lst, nlist[b - 1].lst);
  }
  return 0;
}
