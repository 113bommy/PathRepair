#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, count = 0, count2 = 0;
  cin >> a >> b;
  int arr[a];
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
    if (arr[i] <= b) {
      count++;
    } else {
      count2 += 2;
    }
  }
  cout << count + count2;
}
