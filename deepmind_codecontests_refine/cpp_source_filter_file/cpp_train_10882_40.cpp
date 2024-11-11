#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, sum, arr[100000], k, flag = 0;
  vector<int> nums;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + i);
  sum = 0;
  if (arr[0] > 1) {
    j = arr[0];
    for (i = 1; i < j; i++) {
      if (sum + i <= m) {
        sum += i;
        nums.push_back(i);
      } else {
        break;
        flag = 1;
      }
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (arr[i + 1] - arr[i] > 0) {
      j = arr[i] + 1;
      k = arr[i + 1];
      while (j < k && flag != 1) {
        if (sum + j <= m) {
          sum += j;
          nums.push_back(j);
        } else {
          flag = 1;
        }
        j++;
      }
    }
    if (flag) {
      break;
    }
  }
  i = arr[n - 1] + 1;
  if (!flag) {
    if (i + sum <= m) {
      sum += i;
      nums.push_back(i);
    } else {
      flag = 1;
    }
    i++;
  }
  k = nums.size();
  cout << k << endl;
  for (i = 0; i < k; i++) {
    cout << nums[i] << ' ';
  }
  return 0;
}
