#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
struct point_int {
  int x, y;
  point_int() {}
  point_int(int a, int b) { x = a, y = b; }
};
struct point_double {
  double x, y;
  point_double() {}
  point_double(double a, double b) { x = a, y = b; }
};
struct Node {
  int v, w;
  Node() {}
  bool operator<(const Node &a) const { return w > a.w; }
  Node(int _v, int _w) { v = _v, w = _w; }
};
namespace my {
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <class T>
T multiplication(T n, T p, T m) {
  if (p == 0) return (T)0;
  T x = multiplication(n, p / 2, m);
  x = (x + x) % m;
  if (p & 1) x = (x + n) % m;
  return x;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
double getdist(T a, T b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
template <class T>
T extract(string s, T ret) {
  stringstream ss(s);
  ss >> ret;
  return ret;
}
template <class T>
string tostring(T n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
T MIN3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T MAX3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
void print_vector(T &v) {
  int sz = v.size();
  if (sz) cout << v[0];
  for (int i = 1; i < sz; i++) cout << ' ' << v[i];
  cout << endl;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
bool isConsonant(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
}  // namespace my
int read_int() {
  int n;
  scanf("%d", &n);
  return n;
}
int read_LLD() {
  long long int n;
  scanf("%lld", &n);
  return n;
}
inline int buffer_input() {
  char inp[1000];
  scanf("%s", inp);
  return atoi(inp);
}
int Tree[3 * 500005];
void update(int L, int R, int indx, int x, int value) {
  if (L == R) {
    Tree[indx] = max(value, Tree[indx]);
    return;
  }
  int mid = (L + R) >> 1;
  if (x <= mid)
    update(L, mid, 2 * indx, x, value);
  else
    update(mid + 1, R, 2 * indx + 1, x, value);
  Tree[indx] = max(Tree[2 * indx], Tree[2 * indx + 1]);
}
int query(int L, int R, int indx, int x, int y) {
  if (L == x and R == y) return Tree[indx];
  int mid = (L + R) >> 1;
  if (y <= mid)
    return query(L, mid, 2 * indx, x, y);
  else if (x > mid)
    return query(mid + 1, R, 2 * indx, x, y);
  return max(query(L, mid, 2 * indx, x, mid),
             query(mid + 1, R, 2 * indx + 1, mid + 1, y));
}
tuple<int, int, int> v[500005];
vector<int> B, I, R;
set<int> S;
map<int, int> Map;
int main() {
  cin.sync_with_stdio(false);
  cin.tie();
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    B.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    I.push_back(x);
    S.insert(x);
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    R.push_back(x);
  }
  int cnt = 1;
  for (auto x : S) {
    Map[x] = cnt++;
  }
  int Total = S.size() + 1;
  for (int i = 0; i < N; i++) {
    v[i] = (make_tuple(B[i], Map[I[i]], R[i]));
  }
  sort(v, v + N);
  int ans = 0, last = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    int a = get<0>(v[i]);
    int b = get<1>(v[i]);
    int c = get<2>(v[i]);
    int Max = query(1, Total, 1, b + 1, Total);
    if (Max > c) ans++;
    if (i and a != get<0>(v[i - 1])) {
      while (last >= i)
        update(1, Total, 1, get<1>(v[last]), get<2>(v[last])), last--;
    }
  }
  cout << ans;
  return 0;
}
