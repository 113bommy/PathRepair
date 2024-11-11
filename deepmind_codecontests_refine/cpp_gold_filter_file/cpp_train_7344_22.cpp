#include <bits/stdc++.h>
using namespace std;
int main() {
  int count1 = 0;
  int count2 = 0;
  int x, y, z;
  cin >> x >> y >> z;
  int *arr = new int[x];
  for (int i = 0; i < x; i++) {
    cin >> arr[i];
    if (y >= arr[i]) {
      count2 += arr[i];
    }
    if (count2 > z) {
      count1++;
      count2 = 0;
    }
  }
  cout << count1 << endl;
}
