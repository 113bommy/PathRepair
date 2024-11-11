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
  T res = 1;
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
int N, M, X, Y;
int Parent[200010], Rank[200010], counts[200010];
set<int> non_neigh[200010];
vector<int> leaders, leaders_count;
int Find(int node) {
  return Parent[node] = (Parent[node] != node ? Find(Parent[node]) : node);
}
void Union(int nde_1, int nde_2) {
  if (Rank[nde_1] >= Rank[nde_2]) {
    Parent[nde_2] = nde_1;
    Rank[nde_1] += Rank[nde_2];
  } else {
    Parent[nde_1] = nde_2;
    Rank[nde_2] += Rank[nde_1];
  }
}
int main() {
  scanf("%d%d", &N, &M);
  for (auto i = 0; i < M; ++i) {
    scanf("%d%d", &X, &Y);
    non_neigh[X].insert(Y);
    non_neigh[Y].insert(X);
  }
  for (auto i = 1; i <= N; ++i) {
    non_neigh[i].insert(i);
    Parent[i] = i;
    Rank[i] = 1;
  }
  for (auto i = 1; i <= N; ++i) {
    int node = 1;
    auto itr = non_neigh[i].begin();
    for (auto t = 1; t <= 2; ++t) {
      while (itr != non_neigh[i].end() && node == *itr) {
        ++node, ++itr;
      }
      if (node > N) {
        continue;
      }
      non_neigh[node].insert(i);
      int par_1 = Find(i);
      int par_2 = Find(node);
      if (par_1 != par_2) {
        Union(par_1, par_2);
      }
      ++node;
    }
  }
  int comp = 0;
  for (auto i = 1; i <= N; ++i) {
    int par = Find(i);
    if (par == i) {
      leaders.push_back(i);
    }
    ++counts[par];
  }
  printf("%d\n", (int)leaders.size());
  for (auto elem : leaders) {
    leaders_count.push_back(counts[elem]);
  }
  sort(leaders_count.begin(), leaders_count.end());
  for (auto elem : leaders_count) {
    printf("%d ", elem);
  }
  printf("\n");
  return 0;
}
