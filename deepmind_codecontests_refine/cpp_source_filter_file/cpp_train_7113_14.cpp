#include <bits/stdc++.h>
using namespace std;
int n, k;
bool isPossible(int num) {
  int work_hours = 0;
  long long div = k;
  int temp = num;
  while (temp > 0) {
    work_hours += temp;
    temp = num / div;
    div *= div;
  }
  if (work_hours >= n)
    return true;
  else {
    return false;
  }
}
int binarySearch(int low, int high) {
  while (low < high) {
    int mid = low + (high - low) / 2;
    bool flag = isPossible(mid);
    if (flag)
      high = mid;
    else
      low = mid + 1;
  }
  return low;
}
int main(int argc, char const *argv[]) {
  cin >> n >> k;
  cout << binarySearch(0, n) << endl;
  return 0;
}
