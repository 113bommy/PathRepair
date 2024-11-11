#include <bits/stdc++.h>
using namespace std;
int thanos(int items[], int start, int end) {
  for (int i = start; i < end - 1; i++) {
    if (items[i] > items[i + 1]) {
      int half = (end - start) / 2;
      int item1 = thanos(items, start + half, end);
      int item2 = thanos(items, start, end - half);
      return min(item1, item2);
    }
  }
  return end - start;
}
int main() {
  int n;
  cin >> n;
  int items[n];
  for (int i = 0; i < n; i++) {
    cin >> items[i];
  }
  cout << thanos(items, 0, n) << endl;
  return 0;
}
