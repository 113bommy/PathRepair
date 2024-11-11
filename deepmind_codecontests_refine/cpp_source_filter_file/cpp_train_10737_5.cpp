#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int arr[3] = {0};
  int maxnum;
  maxnum = 0;
  int a, last;
  int flag = 0;
  int currval;
  for (int i = 0; i < x; i++) {
    cin >> a;
    arr[a] = arr[a] + 1;
    if (i == 0) {
      last = a;
      continue;
    }
    if (last != a) {
      flag = flag + 1;
    }
    if (flag == 2) {
      flag = 0;
      arr[a] = 1;
    }
    currval = min(arr[1], arr[2]);
    if (currval > maxnum) {
      maxnum = currval;
    }
    last = a;
  }
  cout << maxnum * 2;
}
