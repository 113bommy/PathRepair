#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> M;
  deque<int> dq;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int i = 0;
  for (; i < n && i < k; i++) {
    if (M.find(arr[i]) == M.end()) {
      dq.push_front(arr[i]);
      M[arr[i]] = 1;
    }
  }
  while (i < n) {
    if (dq.size() < k) {
      if (M.find(arr[i]) == M.end()) {
        dq.push_front(arr[i]);
        M[arr[i]] = 1;
      }
    } else {
      if (M.find(arr[i]) == M.end()) {
        M.erase(dq.back());
        dq.pop_back();
        dq.push_front(arr[i]);
        M[arr[i]] = 1;
      }
    }
    i++;
  }
  deque<int>::iterator it;
  cout << dq.size() << endl;
  for (it = dq.begin(); it != dq.end(); it++) cout << *it << " ";
  return 0;
}
