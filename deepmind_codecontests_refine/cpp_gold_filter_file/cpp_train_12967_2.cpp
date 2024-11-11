#include <bits/stdc++.h>
using namespace std;
int find_mind(int *arr, int n) {
  int min = 20001, mind = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] < min) min = arr[mind = i];
  }
  return mind;
}
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n], cnt[2001] = {0};
  long long t;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= m) cnt[arr[i]]++;
  }
  int k = 0, count = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[find_mind(cnt, m)] >= n / m) break;
    if (arr[i] > m) {
      k = find_mind(cnt, m);
      arr[i] = k;
      cnt[k]++;
      count++;
    }
  }
  if (cnt[find_mind(cnt, m)] < n / m) {
    for (int i = 0; i < n; i++) {
      if (cnt[arr[i]] > n / m) {
        k = find_mind(cnt, m);
        cnt[arr[i]]--;
        arr[i] = k;
        cnt[k]++;
        count++;
      }
      if (cnt[find_mind(cnt, m)] >= n / m) break;
    }
  }
  cout << cnt[find_mind(cnt, m)] << " " << count << "\n";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
