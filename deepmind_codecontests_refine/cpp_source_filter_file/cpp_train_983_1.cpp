#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 2, l = 300, x = 185, y = 230;
  cin >> n >> l >> x >> y;
  vector<long long> in(n);
  set<int> total;
  for (int i = 0; i < n; i++) {
    cin >> in[i];
    total.insert(in[i]);
  }
  set<long long> X;
  for (int i = 0; i < n; i++) {
    int right = in[i] + x;
    int left = in[i] - x;
    if (right <= l) X.insert(right);
    if (left >= 0) X.insert(left);
    if (total.count(left) || total.count(right)) {
      X.clear();
      break;
    }
  }
  set<long long> Y;
  for (int i = 0; i < n; i++) {
    int right = in[i] + y;
    int left = in[i] - y;
    if (right <= l) {
      if (X.count(right)) {
        Y.clear();
        X.clear();
        Y.insert(right);
        break;
      } else {
        Y.clear();
        Y.insert(right);
      }
    }
    if (left >= 0) {
      if (X.count(left)) {
        Y.clear();
        X.clear();
        Y.insert(right);
        break;
      } else {
        Y.clear();
        Y.insert(left);
      }
    }
    if (total.count(left) || total.count(right)) {
      Y.clear();
      break;
    }
  }
  int size = min(1, (int)Y.size()) + min(1, (int)X.size());
  cout << min(2, size) << endl;
  for (long long i : Y) {
    cout << i << " ";
    break;
  }
  for (long long i : X) {
    cout << i << " ";
    break;
  }
}
