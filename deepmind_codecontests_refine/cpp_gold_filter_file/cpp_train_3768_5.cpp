#include <bits/stdc++.h>
using namespace std;
long long arr[500];
deque<int> q;
vector<int> v;
map<int, int> vis;
int main() {
  int q;
  cin >> q;
  while (q--) {
    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      mx = max(mx, arr[i]);
    }
    if (sum % n == 0)
      cout << sum / n << endl;
    else {
      cout << sum / n + 1 << endl;
    }
  }
}
