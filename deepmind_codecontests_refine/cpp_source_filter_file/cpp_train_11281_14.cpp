#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b, id;
  Node() {}
  Node(int a, int b, int id) : a(a), b(b), id(id) {}
};
bool cmp(const Node &p, const Node &q) {
  if (p.a != p.a) return p.a < q.a;
  return p.b < q.b;
}
int main() {
  int cases;
  scanf("%d", &cases);
  for (int tc = 0; tc < cases; ++tc) {
    int n;
    scanf("%d", &n);
    vector<Node> V;
    for (int i = 0; i < 2 * n - 1; ++i) {
      int a, b;
      scanf("%d", &a), scanf("%d", &b);
      V.push_back(Node(a, b, i));
    }
    sort(V.begin(), V.end(), cmp);
    vector<int> vec;
    for (int i = 0; i < n - 1; ++i)
      if (V[2 * i].b > V[2 * i + 1].b)
        vec.push_back(V[2 * i].id);
      else
        vec.push_back(V[2 * i + 1].id);
    vec.push_back(V[2 * n - 2].id);
    puts("YES");
    for (int i = 0; i < ((int)(vec).size()); ++i)
      printf("%d%c", vec[i] + 1, i + 1 == ((int)(vec).size()) ? 10 : 32);
  }
}
