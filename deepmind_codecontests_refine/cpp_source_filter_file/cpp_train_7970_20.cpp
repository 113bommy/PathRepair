#include <bits/stdc++.h>
using namespace std;
int greatestNumLessThanTarget(vector<int>& a, int target) {
  int start = 0;
  int end = a.size() - 1;
  int ret = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (a[mid] == target) {
      ret = mid;
      break;
    } else if (a[mid] > target) {
      end = mid - 1;
    } else {
      ret = mid;
      start = mid + 1;
    }
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  int k;
  cin >> k;
  vector<int> a(N, 0);
  int timeleft = 240 - k;
  int timeonClock;
  for (int i = 0; i < N; i++) a[i] = i == 0 ? 0 : a[i - 1] + 5 * (i + 1);
  int index;
  index = greatestNumLessThanTarget(a, timeleft);
  cout << (index + 1);
  return 0;
}
