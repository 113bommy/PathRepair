#include <bits/stdc++.h>
using namespace std;
int minimumSubscriptions(int n, int d, int arr[]) {
  int freq[100];
  memset(freq, 0, sizeof(freq));
  int i;
  int temp = 0;
  deque<int> q;
  for (i = 0; i < d; i++) {
    q.push_back(arr[i]);
    if (freq[arr[i]] == 0) {
      temp++;
    }
    freq[arr[i]]++;
  }
  int ans = temp;
  for (; i < n; i++) {
    int x = q.front();
    freq[x]--;
    if (freq[x] == 0) {
      temp--;
    }
    q.pop_front();
    q.push_back(arr[i]);
    if (freq[arr[i]] == 0) {
      temp++;
    }
    freq[arr[i]]++;
    ans = min(ans, temp);
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    int n, k, d;
    cin >> n >> k >> d;
    int arr[100];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << minimumSubscriptions(n, d, arr) << endl;
    t--;
  }
  return 0;
}
