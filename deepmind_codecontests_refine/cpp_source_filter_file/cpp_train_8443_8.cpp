#include <bits/stdc++.h>
using namespace std;
struct laptop {
  int speed;
  int ram;
  int hdd;
  int cost;
  int idx;
  bool operator<(const laptop& A) const { return cost < A.cost; }
} arr[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s;
  bool f = false;
  cin >> s;
  for (int i = 0; i < s; i++) {
    cin >> arr[i].speed >> arr[i].ram >> arr[i].hdd >> arr[i].cost;
    arr[i].idx = i + 1;
  }
  sort(arr, arr + s);
  for (int i = 0; i < s; i++) {
    f = false;
    for (int j = 0; j < s && !f; j++) {
      if (i != j) {
        if (arr[i].speed > arr[j].speed || arr[i].ram > arr[j].ram ||
            arr[i].hdd > arr[j].hdd)
          continue;
        f = true;
      }
    }
    if (!f) {
      cout << arr[i].idx;
      return 0;
    }
  }
}
