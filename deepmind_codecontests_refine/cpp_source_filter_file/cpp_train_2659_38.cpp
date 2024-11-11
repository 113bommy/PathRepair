#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, count1 = 0, count2 = 0;
  cin >> a >> b;
  int arr[a];
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
    if (arr[i] <= b) {
      count1++;
    } else {
      count2++;
    }
  }
  cout << count1 + count2;
}
