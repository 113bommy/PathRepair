#include <bits/stdc++.h>
using namespace std;
int n, arr[500000], fen[500000];
void update(int index, int val) {
  while (index <= n) {
    fen[index] = max(fen[index], val);
    index += index & -index;
  }
}
int query(int index) {
  int sum = 0;
  while (index > 0) {
    sum = max(fen[index], sum);
    index -= index & -index;
  }
  return sum;
}
int main() {
  int i, ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> arr[i];
  for (i = 0; i < n; i++) {
    update(arr[i], query(arr[i]) + 1);
  }
  cout << query(n);
}
