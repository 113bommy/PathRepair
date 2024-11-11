#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int n = 0;
void init() {
  queue<string> q;
  q.push("4");
  q.push("7");
  while (!q.empty()) {
    string u = q.front();
    q.pop();
    arr[n++] = stoi(u);
    if (u.length() < 9) {
      q.push(u + "4");
      q.push(u + "7");
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  init();
  int t = 3;
  while (t--) {
    int k;
    cin >> k;
    cout << lower_bound(arr, arr + n, k) - arr + 1 << endl;
  }
  return 0;
}
