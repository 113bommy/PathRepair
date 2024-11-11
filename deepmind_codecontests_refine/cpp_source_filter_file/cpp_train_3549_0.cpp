#include <bits/stdc++.h>
using namespace std;
int ddx[] = {1, 0};
int ddy[] = {0, 1};
int n, m, peso;
vector<long long int> aa, bb;
vector<double> vec;
double ans = DBL_MAX;
bool can(double atual) {
  double a = peso + atual;
  bool at = false;
  for (int i = 0; i < int(vec.size()); i++) {
    a = (a - (a / vec[i]));
  }
  if (a < peso) return false;
  ans = min(ans, atual);
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> peso;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    aa.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    bb.push_back(a);
  }
  bool at = false;
  int a = 0, b = 1;
  while (1) {
    if (!at)
      vec.push_back(aa[a++]), at = true;
    else if (at)
      vec.push_back(bb[b++]), at = false;
    if (a == int(aa.size())) {
      vec.push_back(bb[0]);
      break;
    }
  }
  double com = 0, fim = DBL_MAX;
  int it = 0;
  while (com < fim) {
    double mid = com + (fim - com) / 2;
    if (can(mid))
      fim = mid;
    else
      com = mid;
    int aaa = com, bbb = fim;
    it++;
    if (it == 10000) break;
  }
  if (ans == DBL_MAX)
    printf("1");
  else
    printf("%.8lf\n", ans);
  return 0;
}
