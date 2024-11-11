#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 5;
int N;
struct Node {
  int x1, y1, x2, y2;
};
Node arr[maxn];
bool cmp1(int A, int B) {
  Node a = arr[A];
  Node b = arr[B];
  return a.x1 == b.x1 ? a.x2 < b.x2 : a.x1 < b.x1;
}
bool cmp2(int A, int B) {
  Node a = arr[A];
  Node b = arr[B];
  return a.y1 == b.y1 ? a.y2 < b.y2 : a.y1 < b.y1;
}
bool solve(vector<int>& v) {
  if (v.size() == 1) return 1;
  vector<int> s;
  sort(v.begin(), v.end(), cmp1);
  int x = arr[v[0]].x2;
  for (int i = 1; i < v.size(); i++) {
    Node tem = arr[v[i]];
    if (tem.x1 >= x) {
      s.clear();
      for (int j = 0; j < i; j++) s.push_back(v[j]);
      if (!solve(s)) return 0;
      s.clear();
      for (int j = i; j < v.size(); j++) s.push_back(v[j]);
      return solve(s);
    }
    x = max(x, tem.x2);
  }
  sort(v.begin(), v.end(), cmp2);
  int y = arr[v[0]].y2;
  for (int i = 1; i < v.size(); i++) {
    Node tem = arr[v[i]];
    if (tem.y1 >= y) {
      s.clear();
      for (int j = 0; j < i; j++) s.push_back(v[j]);
      if (!solve(s)) return 0;
      s.clear();
      for (int j = i; j < v.size(); j++) s.push_back(v[j]);
      return solve(s);
    }
    y = max(y, tem.y2);
  }
  return 0;
}
int main() {
  vector<int> v;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    arr[i] = (Node){a, b, c, d};
    v.push_back(i);
  }
  if (solve(v))
    puts("YES");
  else
    puts("NO");
}
