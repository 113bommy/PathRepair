#include <bits/stdc++.h>
using namespace std;
int i, j, y, n, m, a, b, c, a8;
string s, l;
char u, k;
map<char, string> t;
int main() {
  cin >> k >> s;
  t['q'] = "pw";
  t['w'] = "qe";
  t['e'] = "wr";
  t['r'] = "et";
  t['t'] = "ry";
  t['y'] = "tu";
  t['u'] = "yi";
  t['i'] = "uo";
  t['o'] = "ip";
  t['p'] = "oo";
  if (k == 'R')
    n = 0;
  else
    n = 1;
  t['a'] = "ss";
  t['s'] = "ad";
  t['d'] = "sf";
  t['f'] = "dg";
  t['g'] = "fh";
  t['h'] = "gj";
  t['j'] = "hk";
  t['k'] = "jl";
  t['l'] = "k;";
  t[';'] = "ll";
  t['z'] = "xi";
  t['x'] = "zc";
  t['c'] = "xv";
  t['v'] = "cb";
  t['b'] = "vn";
  t['n'] = "bm";
  t['m'] = "n,";
  t[','] = "m.";
  t['.'] = ",/";
  t['/'] = "..";
  for (i = 0; i < s.size(); i++) {
    u = s[i];
    l = t[u];
    cout << l[n];
  }
}
