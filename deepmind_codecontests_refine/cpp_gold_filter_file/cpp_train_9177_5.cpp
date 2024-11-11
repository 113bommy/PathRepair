#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, id;
};
bool cmpx(node a, node b) { return a.x < b.x; }
bool cmpid(node a, node b) { return a.id < b.id; }
vector<node> p;
int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    p.push_back(node{x, i});
  }
  sort(p.begin(), p.end(), cmpx);
  for (int i = 0; i < n; i++)
    if (p[i].x >= 0) p[i].x = -p[i].x - 1;
  if (n % 2 == 1) {
    sort(p.begin(), p.end(), cmpx);
    p[0].x = -p[0].x - 1;
  }
  sort(p.begin(), p.end(), cmpid);
  for (int i = 0; i < n; i++) cout << p[i].x << ' ';
  return 0;
}
