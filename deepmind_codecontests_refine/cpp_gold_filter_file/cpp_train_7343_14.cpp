#include <bits/stdc++.h>
using namespace std;
int n, arr[100], s;
bool notSorted();
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  while (notSorted()) {
    int val = 1e9, idx = s;
    for (int i = s; i < n; i++)
      if (arr[i] < val) val = arr[i], idx = i;
    while (idx > s) {
      printf("%d %d\n", idx, idx + 1);
      swap(arr[idx], arr[idx - 1]);
      idx--;
    }
    s++;
  }
}
bool notSorted() {
  for (int i = 1; i < n; i++)
    if (arr[i] < arr[i - 1]) return true;
  return false;
}
