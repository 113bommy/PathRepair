#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> add(1, 0), el(1, 0);
long long sum = 0;
void addV(int x, int a) {
  add[a - 1] += x;
  sum += a * x;
}
void addEl(int k) {
  add.push_back(0);
  el.push_back(k);
  sum += k;
}
void del() {
  if (add.size() == 1) return;
  sum -= add.back();
  add[add.size() - 2] += add.back();
  add.pop_back();
  sum -= el.back();
  el.pop_back();
}
int main() {
  cout.precision(20);
  cin >> n;
  int t, x, a, k;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> a >> x;
      addV(x, a);
    } else if (t == 2) {
      cin >> k;
      addEl(k);
    } else if (t == 3) {
      del();
    } else
      assert(false);
    cout << (long double)sum / el.size() << endl;
  }
  return 0;
}
