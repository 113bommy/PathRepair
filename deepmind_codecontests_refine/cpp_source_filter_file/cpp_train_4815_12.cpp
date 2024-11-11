#include <bits/stdc++.h>
using namespace std;
const int limit = 1e6 + 5;
int tree[limit << 1] = {0};
int a;
void update(int index, int v) {
  index += limit;
  while (index) {
    tree[index] += v;
    index >>= 1;
  }
}
int recur(int here) {
  int L = (here << 1);
  int R = L + 1;
  if (L >= limit) {
    if (a <= tree[L])
      return L - limit;
    else
      return R - limit;
  }
  if (a <= tree[L]) {
    return recur(L);
  } else {
    a -= tree[L];
    return recur(R);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, q, left;
  cin >> n >> q;
  left = n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    update(a, 1);
  }
  for (int i = 0; i < q; i++) {
    cin >> a;
    if (a < 0) {
      left--;
      a = -a;
      update(recur(1), -1);
    } else {
      left++;
      update(a, 1);
    }
  }
  if (left == 0) {
    cout << 0;
    return 0;
  }
  const int bound = (limit << 1);
  for (int i = limit; i < bound; i++) {
    if (tree[i]) {
      cout << i - limit;
      return 0;
    }
  }
  return 0;
}
