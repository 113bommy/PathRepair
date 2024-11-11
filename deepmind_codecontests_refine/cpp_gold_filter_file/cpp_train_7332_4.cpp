#include <bits/stdc++.h>
using namespace std;
class Data {
 public:
  int i, x, y, k;
  long int r;
  Data(const int x, const int y, const int k, const int i) {
    this->x = x;
    this->y = y;
    this->k = k;
    this->i = i;
    this->r = x * x + y * y;
  }
  bool operator<(const Data& right) const { return r < right.r; }
};
const int MEGA = 1000000;
int main() {
  int n, s;
  long int r2;
  vector<Data> hoge;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    hoge.push_back(Data(x, y, k, i));
  }
  sort(hoge.begin(), hoge.end());
  for (int i = 0; i < n; i++) {
    if (s >= MEGA) break;
    s += hoge[i].k;
    r2 = hoge[i].r;
  }
  if (s >= MEGA) {
    printf("%.7f\n", sqrt((double)r2));
  } else {
    cout << -1 << endl;
  }
  return 0;
}
