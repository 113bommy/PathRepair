#include <bits/stdc++.h>
using namespace std;
struct Node {
  static const int MAX = 1 << 21;
  int low{MAX};
  int high{-1};
  int diff{MAX};
  operator bool() const { return low < MAX; }
};
void merge(vector<Node> &v, const int &start, const int &half_step) {
  for (int i = start; i < start + half_step; ++i) {
    const int only_diff = min(v[i].diff, v[i + half_step].diff);
    const int diff1 = min(only_diff, v[i + half_step].low - v[i].high);
    const int diff2 = min(only_diff, (v[i].low ^ half_step) -
                                         (v[i + half_step].high ^ half_step));
    v[i].diff = diff1;
    v[i + half_step].diff = diff2;
    const int low1 = min(v[i].low, v[i + half_step].low);
    const int low2 =
        min(v[i].low ^ half_step, v[i + half_step].low ^ half_step);
    v[i].low = low1;
    v[i + half_step].low = low2;
    const int high1 = max(v[i].high, v[i + half_step].high);
    const int high2 =
        max(v[i].high ^ half_step, v[i + half_step].high ^ half_step);
    v[i].high = high1;
    v[i + half_step].high = high2;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  int num = 1 << k;
  vector<Node> first_round(num);
  for (; n > 0; --n) {
    int a;
    cin >> a;
    first_round[a].low = a;
    first_round[a].high = a;
  }
  for (int deg = 0; deg < k; ++deg) {
    const int half_step = 1 << deg;
    const int step = 2 * half_step;
    for (int i = 0; i < num; i += step) merge(first_round, i, half_step);
  }
  for (int i = 0; i < num; ++i) cout << first_round[i].diff << " ";
  cout << endl;
}
