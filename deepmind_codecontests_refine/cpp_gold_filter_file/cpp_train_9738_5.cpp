#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k;
string str;
int first[maxn], sum[maxn];
int Sum(int x, int y) {
  if (x == 0) {
    return sum[y];
  } else {
    return sum[y] - sum[x - 1];
  }
}
int binary_search(int loc) {
  int left = 0, right = loc, mid, ret = loc;
  while (left <= right) {
    mid = (left + right) / 2;
    if (Sum(mid, loc) <= k) {
      ret = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return ret;
}
int solve(char c) {
  int start_loc = 0;
  if (str[0] == c) {
    first[0] = 0;
    sum[0] = 0;
  } else {
    first[0] = -1;
    sum[0] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (str[i] == c) {
      if (str[i - 1] == c) {
        first[i] = first[i - 1];
      } else {
        first[i] = i;
      }
    } else {
      first[i] = -1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (str[i] != c) {
      sum[i] = sum[i - 1] + 1;
    } else {
      sum[i] = sum[i - 1];
    }
  }
  int ans = 0;
  for (int i = n - 1; i >= 0;) {
    if (str[i] == c) {
      if (sum[i] <= k) {
        ans = max(ans, i + 1);
      } else {
        int find_index = binary_search(i);
        ans = max(ans, i - find_index + 1);
      }
      i = first[i] - 1;
    } else {
      int find_index = binary_search(i);
      ans = max(ans, i - find_index + 1);
      --i;
    }
  }
  return ans;
}
int main() {
  cin >> n >> k >> str;
  char target[2] = {'a', 'b'};
  int ans = 0;
  for (int i = 0; i < 2; ++i) {
    ans = max(solve(target[i]), ans);
  }
  cout << ans << endl;
  return 0;
}
