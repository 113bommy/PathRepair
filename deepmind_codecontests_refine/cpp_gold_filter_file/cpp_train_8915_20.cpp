#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int first;
    scanf("%d", &first);
    arr.push_back(first - i);
  }
  vector<int> A, bi;
  int ans = n;
  for (int i = 0; i < n; i++) {
    int pos = upper_bound(bi.begin(), bi.end(), arr[i]) - bi.begin();
    A.push_back(pos + 1);
    if (pos == bi.size())
      bi.push_back(arr[i]);
    else
      bi[pos] = arr[i];
    ans = min(ans, n - 1 - A[i]);
  }
  bi.clear();
  deque<pair<int, int> > sta;
  for (int i = n - 1; i >= 2; i--) {
    int pos = upper_bound(bi.begin(), bi.end(), -arr[i]) - bi.begin();
    if (pos == bi.size())
      bi.push_back(-arr[i]);
    else
      bi[pos] = -arr[i];
    while (sta.size() && arr[i] >= sta.front().first) {
      if (pos + 1 >= sta.front().second)
        sta.pop_front();
      else
        break;
    }
    if (sta.empty() ||
        arr[i] < sta.front().first && pos + 1 > sta.front().second)
      sta.push_front({arr[i], pos + 1});
    auto it = lower_bound(sta.begin(), sta.end(),
                          (pair<int, int>){arr[i - 2] - 1, -12341234});
    if (it != sta.end()) ans = min(ans, n - 1 - A[i - 2] - it->second);
  }
  printf("%d\n", max(ans, 0));
}
