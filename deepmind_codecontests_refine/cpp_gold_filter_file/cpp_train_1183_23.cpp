#include <bits/stdc++.h>
using namespace std;
int i, j, k;
int temp;
int n;
int array[100001];
map<int, int> below;
struct sqr {
  int x;
} sqrs[100000];
bool compare(sqr a, sqr b) {
  if (a.x <= b.x) return 1;
  return 0;
}
int posi;
int posj;
int main() {
  cin >> n >> k;
  for (i = ((0)); i < ((n)); ++i) {
    cin >> sqrs[i].x;
  }
  if (k > n) {
    cout << -1 << endl;
  } else {
    sort(sqrs, sqrs + n, compare);
    cout << sqrs[n - k].x << " " << sqrs[n - k].x << endl;
  }
  return 0;
}
