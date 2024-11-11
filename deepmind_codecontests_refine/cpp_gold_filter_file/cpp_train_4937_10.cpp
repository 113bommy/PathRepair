#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
ostream &operator<<(ostream &out, pair<T, T1> obj) {
  out << "(" << obj.first << "," << obj.second << ")";
  return out;
}
template <typename T, typename T1>
ostream &operator<<(ostream &out, map<T, T1> cont) {
  typename map<T, T1>::const_iterator itr = cont.begin();
  typename map<T, T1>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> cont) {
  typename set<T>::const_iterator itr = cont.begin();
  typename set<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> cont) {
  typename multiset<T>::const_iterator itr = cont.begin();
  typename multiset<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T,
          template <typename ELEM, typename ALLOC = allocator<ELEM>> class CONT>
ostream &operator<<(ostream &out, CONT<T> cont) {
  typename CONT<T>::const_iterator itr = cont.begin();
  typename CONT<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator<<(basic_ostream<CTy, CTr> &out, const T (&arr)[N]) {
  for (auto i = 0; i < N; ++i) out << arr[i] << " ";
  out << endl;
  return out;
}
template <typename T>
T gcd(T a, T b) {
  T min_v = min(a, b);
  T max_v = max(a, b);
  while (min_v) {
    T temp = max_v % min_v;
    max_v = min_v;
    min_v = temp;
  }
  return max_v;
}
template <typename T>
T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
T fast_exp_pow(T base, T exp, T mod) {
  long long res = 1;
  while (exp) {
    if (exp & 1) {
      res *= base;
      res %= mod;
    }
    exp >>= 1;
    base *= base;
    base %= mod;
  }
  return res % mod;
}
int Q, V;
int dist1, dist2, dist3, dist4;
int cnt = 5, leaf1 = 2, leaf2 = 3, diameter = 2;
int depth[1000010];
int parent[1000010][25];
void process(int node, int par) {
  parent[node][0] = par;
  depth[node] = depth[par] + 1;
  for (auto i = 1; i < 25; ++i) {
    if (parent[node][i - 1] == -1) break;
    parent[node][i] = parent[parent[node][i - 1]][i - 1];
  }
}
int LCA(int node1, int node2) {
  if (depth[node1] < depth[node2]) swap(node1, node2);
  for (int i = 25 - 1; i >= 0; --i)
    if (parent[node1][i] != -1 && depth[parent[node1][i]] >= depth[node2])
      node1 = parent[node1][i];
  if (node1 == node2) return node1;
  for (int i = 25 - 1; i >= 0; --i)
    if (parent[node1][i] != -1 && parent[node2][i] != -1 &&
        parent[node1][i] != parent[node2][i]) {
      node1 = parent[node1][i];
      node2 = parent[node2][i];
    }
  return parent[node1][0];
}
int get_dist(int node1, int node2) {
  int lca = LCA(node1, node2);
  return depth[node1] + depth[node2] - 2 * depth[lca];
}
int main() {
  scanf("%d", &Q);
  memset(parent, -1, sizeof(parent));
  depth[1] = 0;
  for (auto i = 2; i <= 4; ++i) {
    parent[i][0] = 1;
    depth[i] = 1;
  }
  while (Q--) {
    scanf("%d", &V);
    process(cnt, V);
    process(cnt + 1, V);
    dist1 = get_dist(cnt, leaf1);
    dist2 = get_dist(cnt, leaf2);
    dist3 = get_dist(cnt + 1, leaf1);
    dist4 = get_dist(cnt + 1, leaf2);
    if (dist1 > diameter) {
      diameter = dist1;
      leaf2 = cnt;
    } else if (dist2 > diameter) {
      diameter = dist2;
      leaf1 = cnt;
    } else if (dist3 > diameter) {
      diameter = dist3;
      leaf2 = cnt + 1;
    } else if (dist4 > diameter) {
      diameter = dist4;
      leaf1 = cnt + 1;
    }
    cnt += 2;
    printf("%d\n", diameter);
  }
  return 0;
}
