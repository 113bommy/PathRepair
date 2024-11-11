#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args), ...);
}
using vcl = vector<long>;
using vcc = vector<char>;
using vcs = vector<string>;
using vcd = vector<double>;
using vcll = vector<long long>;
using vcb = vector<bool>;
using vc = vector<int>;
using si = set<int>;
using sll = set<long long>;
using sl = set<long>;
using sc = set<char>;
using ss = set<string>;
void printV(vcll &v) {
  for (auto i : v) write(i, " ");
}
int main() {
  int t;
  read(t);
  int p;
  read(p);
  int q = 7 - p;
  bool alu = true;
  while (t--) {
    long long a, b;
    read(a, b);
    if (a == p || a == q || b == p || b == q) {
      alu = false;
      break;
    }
  }
  if (alu)
    write("yes");
  else
    write("no");
}
