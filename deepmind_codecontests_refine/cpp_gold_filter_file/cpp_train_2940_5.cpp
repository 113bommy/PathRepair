#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 69;
int heap[N], idx[N], val[N];
int g, h;
void dream(int curr) {
  while (curr < ((1 << (h - 1)) - 1) &&
         heap[curr] > min(heap[2 * curr + 1], heap[2 * curr + 2])) {
    int& left = heap[2 * curr + 1];
    int& right = heap[2 * curr + 2];
    if (left < right) {
      swap(left, heap[curr]);
      curr = 2 * curr + 1;
    } else {
      swap(right, heap[curr]);
      curr = 2 * curr + 2;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &h, &g);
    set<int> remain;
    for (int j = 0; j < (1 << h) - 1; j++) {
      scanf("%d", &heap[j]);
      remain.insert(heap[j]);
      idx[heap[j]] = j;
    }
    for (int j = (1 << h) - 2; j >= (1 << g) - 1; j--) dream(j);
    for (int j = (1 << (g - 1)) - 1; j < (1 << g) - 1; j++) {
      val[j] = min(heap[2 * j + 1], heap[2 * j + 2]);
      dream(j);
    }
    for (int j = (1 << (g - 1)) - 2; j >= 0; j--) {
      int lbound = max(val[2 * j + 1], val[2 * j + 2]);
      while (heap[2 * j + 1] <= lbound) {
        heap[2 * j + 1] = INT_MAX;
        dream(2 * j + 1);
      }
      while (heap[2 * j + 2] <= lbound) {
        heap[2 * j + 2] = INT_MAX;
        dream(2 * j + 2);
      }
      val[j] = min(heap[2 * j + 1], heap[2 * j + 2]);
      dream(j);
    }
    long long ans1 = 0;
    for (int j = 0; j < (1 << g) - 1; j++) {
      ans1 += val[j];
      remain.erase(val[j]);
    }
    printf("%I64d\n", ans1);
    for (auto v : remain) printf("%d ", idx[v] + 1);
    printf("\n");
  }
}
