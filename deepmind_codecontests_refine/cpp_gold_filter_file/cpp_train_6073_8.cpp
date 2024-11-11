#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
using v = vector<T>;
const string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
const string alphabetHigher = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string digits = "0123456789";
const long double pi = 3.141592653589793, e = 2.718281828459045;
void read() {}
void print() {}
void debug() { cerr << endl; }
int gcd(int a, int b) {
  if (a < 0) a = abs(a);
  if (b < 0) b = abs(b);
  if (a > b) swap(a, b);
  if (a) return gcd(a, b % a);
  return b;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
struct vt {
  int x, y;
  vt operator-() { return vt(-this->x, -this->y); }
  vt operator+(vt b) { return {this->x + b.x, this->y + b.y}; }
  vt operator-(vt b) { return *this + (-b); }
  vt operator*(int b) { return vt(this->x * b, this->y * b); }
  int operator*(vt b) { return this->x * b.x + this->y * b.y; }
  vt operator/(int b) { return vt(this->x / b, this->y / b); }
  int operator%(vt b) { return this->x * b.y - b.x * this->y; }
  bool operator==(vt b) { return this->x == b.x && this->y == b.y; }
  bool operator!=(vt b) { return !((*this) == b); }
  bool collinear(vt b) { return (*this) % b == 0; }
  bool opposite(vt b) { return this->collinear(b) && (*this) * b < 0; }
  double length() { return sqrt(this->x * this->x + this->y * this->y); }
  vt() {}
  vt(int x, int y) : x(x), y(y) {}
  vt(int x1, int y1, int x2, int y2) : x(x2 - x1), y(y2 - y1) {}
};
int fact(int a) {
  if (a == 1)
    return 1;
  else
    return a * fact(a - 1);
}
int sign(int a) {
  if (a > 0) return 1;
  if (a == 0) return 0;
  return -1;
}
bool prime(int a) {
  if (a < 2) return 0;
  if (a == 2) return 1;
  for (int b = 2; b <= ceil(sqrt(a)); b++)
    if (a % b == 0) return 0;
  return 1;
}
int hashStr(string& s) {
  int base = 26;
  int res = 0;
  for (int i = 0; i < ((long long)(s).length()); i++)
    res =
        ((res * base) % 36028797018963913 + s[i] - 'a' + 1) % 36028797018963913;
  return (res + 36028797018963913) % 36028797018963913;
}
int hashStr(int prevHash, char curChar) {
  return ((prevHash * 26) % 36028797018963913 + curChar - 'a' + 1) %
         36028797018963913;
}
struct node {
  node *left = nullptr, *right = nullptr;
  int w, val, sz = 1;
  node(int val) : w((rand() << 16) + rand()), val(val) {}
};
int siz(node* a) {
  if (a == nullptr)
    return 0;
  else
    return a->sz;
}
node* treap;
node* merge1(node* v1, node* v2) {
  if (v1 == nullptr) return v2;
  if (v2 == nullptr) return v1;
  if (v1->w > v2->w) {
    v1->right = merge1(v1->right, v2);
    v1->sz = siz(v1->left) + siz(v1->right) + 1;
    return v1;
  } else {
    v2->left = merge1(v1, v2->left);
    v2->sz = siz(v2->left) + siz(v2->right) + 1;
    return v2;
  }
}
pair<node*, node*> split(node* w, int k) {
  if (w == nullptr) return {nullptr, nullptr};
  if (siz(w->left) >= k) {
    auto tmp = split(w->left, k);
    w->left = tmp.second;
    w->sz = siz(w->left) + siz(w->right) + 1;
    return {tmp.first, w};
  } else {
    auto tmp = split(w->right, k - siz(w->left) - 1);
    w->right = tmp.first;
    w->sz = siz(w->left) + siz(w->right) + 1;
    return {w, tmp.second};
  }
}
ifstream fin("input.txt");
ofstream fout("output.txt");
template <typename Arg, typename... Args>
void read(Arg& arg, Args&... args) {
  cin >> arg;
  read(args...);
}
template <typename Arg, typename... Args>
void print(Arg arg, Args... args) {
  cout << (arg) << " ";
  print(args...);
}
template <typename Arg, typename... Args>
void debug(Arg arg, Args... args) {
  cerr << (arg) << " ";
  debug(args...);
}
void prnt(node* a) {
  if (a == nullptr) return;
  prnt(a->left);
  print(a->val);
  prnt(a->right);
}
void run() {
  int d;
  cin >> d;
  int cur = 13;
  if (d >= 8000) {
    d -= 7999;
    cur = 758634;
  } else if (d >= 6000) {
    d -= 5999;
    cur = 371191;
  } else if (d >= 4000) {
    d -= 3999;
    cur = 190027;
  }
  unordered_set<int> ps;
  while (d) {
    if (ps.count(cur) || prime(cur)) {
      ps.insert(cur);
      int ruc = 0;
      int p = cur;
      while (p) {
        ruc = ruc * 10 + p % 10;
        p /= 10;
      }
      if (ruc != cur && (ps.count(ruc) || prime(ruc))) {
        d--;
        ps.insert(ruc);
      }
    }
    cur++;
  }
  cout << cur - 1;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  run();
  return 0;
}
