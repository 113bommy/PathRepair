#include <bits/stdc++.h>
using namespace std;
bool found;
int n, x, nums[1000];
void Greedy() {
  int median = (n + 1) / 2;
  sort(nums, nums + n);
  if (nums[--median] == x) {
    printf("0");
    return;
  }
  int smaller, larger;
  if (found) {
    int index = -1;
    for (int i = 0; nums[i] <= x && i < n; i++)
      if (x == nums[i] && abs(index - median) > abs(i - median)) index = i;
    smaller = index;
    larger = n - index - 1;
    printf("%d", larger - smaller - (larger >= smaller));
  } else {
    for (smaller = 0; smaller < n && nums[smaller] < x; smaller++)
      ;
    larger = n - smaller;
    printf("%d", abs(smaller - larger) + (smaller >= larger));
  }
}
int main() {
  found = false;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    found |= (nums[i] == x);
  }
  Greedy();
}
