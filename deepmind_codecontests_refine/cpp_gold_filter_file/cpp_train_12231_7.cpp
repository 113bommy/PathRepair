#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int amount;
  int arr[210001];
  int del[210001];
  Tree() {
    cin >> amount;
    for (int i = 0; i < amount; ++i) {
      cin >> arr[i];
    }
  }
  int left(int ii, int pp) {
    if (pp == 0) return amount - 1;
    return (ii - 1) / pp;
  }
  int right(int ii, int pp) { return (ii - 1) / (pp + 1); }
  void result() {
    int sum = 0;
    for (int i = 1; i < amount; ++i) {
      sum += del[i];
      cout << sum << " ";
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  cout << fixed;
  Tree Pr;
  for (int i = 1; i < Pr.amount; ++i) {
    int p;
    for (p = 0; p * p <= i - 1; ++p) {
      if (Pr.arr[i] < Pr.arr[p]) {
        ++Pr.del[Pr.right(i, p) + 1];
        --Pr.del[Pr.left(i, p) + 1];
      }
    }
    for (int k = 1; k <= (i - 1) / p; ++k) {
      int par = (i - 1) / k;
      if (Pr.arr[i] < Pr.arr[par]) ++Pr.del[k], --Pr.del[k + 1];
    }
  }
  Pr.result();
  return 0;
}
