#include <bits/stdc++.h>
using namespace std;
bool found;
int n, x, nums[1000];
void Greedy() {
  int median = ((n + 1) / 2);
  sort(nums, nums + n);
  if (nums[--median] == x) {
    printf("0");
    return;
  }
  int smaller, larger;
  if (found) {
    smaller = -1;
    for (int i = 0; i < n && nums[i] <= x; i++)
      if (x == nums[i] && abs(smaller - median) > abs(i - median)) smaller = i;
    larger = n - smaller - 1;
    printf("%d", abs(smaller - larger) - (larger > smaller));
  } else {
    for (smaller = 0; smaller < n && nums[smaller] <= x; smaller++)
      ;
    larger = n - smaller;
    printf("%d", 1 + abs(smaller - larger) - (larger > smaller));
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
