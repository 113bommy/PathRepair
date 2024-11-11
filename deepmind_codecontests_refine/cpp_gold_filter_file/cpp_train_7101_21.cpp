#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkMin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T Myabs(T a) {
  return a > 0 ? a : -a;
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int inf = 0x3f3f3f3f;
const long long linf = 1LL << 60;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = 100000007;
const int maxn = 1000100;
struct Node {
  int id;
  string s;
  bool friend operator<(Node a, Node b) { return a.s > b.s; }
} node;
long long k, len;
string str;
int main() {
  cin >> str >> k;
  len = str.length();
  priority_queue<Node> pq;
  if (k * 2 > len * (len + 1))
    puts("No such line.");
  else {
    for (int i = 0; i < len; i++) {
      node.id = i;
      node.s = str[i];
      pq.push(node);
    }
    for (int i = 0; i < k - 1; i++) {
      node = pq.top();
      pq.pop();
      if (node.id != len - 1) {
        node.s += str[++node.id];
        pq.push(node);
      }
    }
    cout << pq.top().s << endl;
  }
  return 0;
}
