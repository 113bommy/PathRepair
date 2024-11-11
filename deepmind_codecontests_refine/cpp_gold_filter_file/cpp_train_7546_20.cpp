#include <bits/stdc++.h>
using namespace std;
vector<string> token(string a) {
  vector<string> w;
  a.push_back(' ');
  while (!a.empty()) {
    w.push_back(a.substr(0, a.find(" ")));
    a = a.substr(a.find(" ") + 1, a.size() - 1);
  }
  return w;
}
map<string, int> mapik;
vector<string> amapik;
int dodaj(string a) {
  if (mapik.count(a) == 0) {
    mapik[a] = mapik.size() - 1;
    amapik.push_back(a);
  }
  return mapik[a];
}
char tmp_str[1000];
string scanf_string() {
  scanf("%s", tmp_str);
  return tmp_str;
}
const int N = 100500;
int n;
const long long M = 1000000007;
long long dwu[4 * N];
inline long long nwd_modulo(const long long &a, const long long &b) {
  return a - a / b * b;
}
long long nwd(const long long &a, const long long &b, long long &x,
              long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long nx, ny;
    long long nwd_war = nwd(b, nwd_modulo(a, b), nx, ny);
    x = ny;
    y = nx - a / b * ny;
    return nwd_war;
  }
}
long long odwrotnosc_modulo(const long long &a, long long p) {
  long long nx, ny;
  long long nwd_war = nwd(a, p, nx, ny);
  if (!(nwd_war == 1)) return -1;
  return nwd_modulo((p + nwd_modulo(nx, p)), p);
}
void init() {
  dwu[n - 1] = 1;
  for (int i = n; i < 3 * n; i++) {
    dwu[i] = ((dwu[i - 1] * i) % M * odwrotnosc_modulo(i - n + 1, M)) % M;
  }
}
long long dwuM(int k) {
  if (k < n - 1)
    return 0;
  else
    return dwu[k];
}
int main() {
  scanf("%d", &n);
  long long b = 0;
  init();
  for (int i = 0; i < n; i++) {
    b = (b + dwuM(n - 1 + i)) % M;
  }
  long long res = 2 * b - n;
  printf("%d\n", (int)(res % M));
  return 0;
}
