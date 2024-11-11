#include <bits/stdc++.h>
using namespace std;
struct num {
  int n, ind;
};
int cmp(num n1, num n2) { return n1.n < n2.n; }
void calc() {
  int n;
  signed long long k;
  int nums[100000], ns[100000];
  cin >> n >> k;
  for (int i = 0; i < (n); i++) {
    scanf("%d", &nums[i]);
    ns[i] = nums[i];
  }
  sort(ns, ns + n);
  int i = 0, mm = 0, make_pair = 0;
  while (k > 0 && i < n) {
    signed long long sub = (signed long long)(ns[i] - mm) * (n - i);
    if (sub <= k) {
      k -= sub;
      mm = ns[i];
    } else {
      while (k >= n - i) {
        k -= n - i;
        make_pair++;
      }
      break;
    }
    i++;
  }
  int mpos = 0;
  if (i == n && k > 0) {
    printf("-1");
  } else {
    for (int i = 0; i < (n); i++) {
      nums[i] -= min(nums[i], mm);
      if (nums[i] > 0) nums[i] -= min(nums[i], make_pair);
      if (nums[i] > 0 && k > 0) {
        nums[i]--;
        k--;
        if (k == 0) mpos = i;
      }
    }
    for (int i = mpos; i < (mpos + n); i++) {
      if (nums[i % n] > 0) printf("%d ", (i % n) + 1);
    }
  }
}
int main() {
  calc();
  return 0;
}
