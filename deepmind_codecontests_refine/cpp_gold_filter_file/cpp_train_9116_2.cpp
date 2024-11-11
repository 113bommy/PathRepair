#include <bits/stdc++.h>
using namespace std;
template <typename T>
using maxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename Iter>
ostream& _out(ostream& s, Iter b, Iter e) {
  s << "[";
  for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
  s << "]";
  return s;
}
template <typename A, typename B>
ostream& operator<<(ostream& s, const pair<A, B>& p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, const vector<T>& c) {
  return _out(s, begin(c), end(c));
}
bool debug = 0;
template <typename T>
void DEBUG(const T& x) {
  if (debug) cerr << x;
}
template <typename T, typename... Args>
void DEBUG(const T& head, const Args&... tail) {
  if (debug) {
    cerr << head;
    DEBUG(tail...);
  }
}
const int N = 5000 + 5;
enum Optr { NO, OR, XOR, AND };
struct Value {
  Optr type;
  string name, a, b;
} arr[N];
long long hasha[N], hashb[N], hasho[N];
inline int get_val(int, int, int);
inline long long hsah(const string&);
int main(int argc, char* argv[]) {
  if (argc > 1 and string(argv[1]) == "-D") debug = 1;
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].name;
    cin >> arr[i].a;
    cin >> arr[i].a;
    if (isdigit(arr[i].a[0])) {
      arr[i].type = NO;
    } else {
      string opt;
      cin >> opt;
      if (opt[0] == 'O')
        arr[i].type = OR;
      else if (opt[0] == 'X')
        arr[i].type = XOR;
      else if (opt[0] == 'A')
        arr[i].type = AND;
      cin >> arr[i].b;
      hasha[i] = hsah(arr[i].a);
      hashb[i] = hsah(arr[i].b);
    }
    hasho[i] = hsah(arr[i].name);
  }
  string mini, maxi;
  for (int i = 0; i < m; i++) {
    if (get_val(i, 0, n) <= get_val(i, 1, n))
      mini.push_back('0');
    else
      mini.push_back('1');
  }
  for (int i = 0; i < m; i++) {
    if (get_val(i, 0, n) >= get_val(i, 1, n))
      maxi.push_back('0');
    else
      maxi.push_back('1');
  }
  cout << mini << '\n' << maxi << '\n';
  return 0;
}
inline int get_val(int pos, int v, int n) {
  unordered_map<long long, int> var;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    if (arr[i].type == NO)
      cur = arr[i].a[pos];
    else {
      int a, b;
      if (arr[i].a == "?")
        a = v;
      else if (!isdigit(arr[i].a[0]))
        a = var[hasha[i]];
      else
        a = arr[i].a[pos] - '0';
      if (arr[i].b == "?")
        b = v;
      else if (!isdigit(arr[i].b[0]))
        b = var[hashb[i]];
      else
        b = arr[i].b[pos] - '0';
      if (arr[i].type == OR)
        cur = a | b;
      else if (arr[i].type == XOR)
        cur = a ^ b;
      else if (arr[i].type == AND)
        cur = a & b;
    }
    var[hasho[i]] = cur;
    ret += cur;
  }
  return ret;
}
inline long long hsah(const string& x) {
  const long long p = 2147483587, q = 127;
  long long ret = 0;
  for (auto i : x) ret = (ret * q % p + i) % p;
  return ret;
}
