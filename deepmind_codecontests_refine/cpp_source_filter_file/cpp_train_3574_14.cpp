#include <bits/stdc++.h>
using namespace std;
bool found;
int n, x, nums[1000], smaller, larger, eq;
void Naive() {
  int median = ((n + 1) / 2);
  sort(nums, nums + n);
  if (nums[--median] == x) {
    printf("0");
    return;
  }
  if (found) {
    for (int i = 0; i < n && nums[i] <= x; i++)
      if (x == nums[i] && abs(smaller - median) > abs(i - median)) smaller = i;
  }
  larger = n - smaller - found;
}
void Smart() {
  larger = n - smaller - eq;
  if (found) {
    eq--;
    int diff = abs(smaller - larger);
    if (larger <= smaller) {
      if (diff <= eq) {
        larger = smaller;
        eq -= diff;
        larger += eq / 2 + (eq % 2);
        smaller += eq / 2;
      } else {
        larger += eq;
        eq = 0;
      }
    } else {
      if (diff <= eq) {
        smaller = larger;
        eq -= diff;
        larger += eq / 2 + (eq % 2);
        smaller += eq / 2;
      } else {
        smaller += eq;
        eq = 0;
      }
    }
  }
}
void Greedy() {
  Naive();
  printf("%d", !found + abs(smaller - larger) - (larger > smaller));
}
int main() {
  found = false;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    smaller += (nums[i] < x);
    eq += (nums[i] == x);
    found |= (nums[i] == x);
  }
  Greedy();
}
