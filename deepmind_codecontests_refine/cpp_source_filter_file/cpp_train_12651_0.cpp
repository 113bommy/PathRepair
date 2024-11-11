#include <bits/stdc++.h>
using namespace std;
int main() {
  int count;
  const int num = 1000000;
  int arr[num];
  int temp;
  int max = 0;
  int max_pos = 0;
  cin >> count;
  for (int i = 0; i < num; i++) {
    arr[i] = 0;
  }
  for (int i = 0; i < count; i++) {
    cin >> temp;
    arr[temp]++;
    if (arr[temp] > max) {
      max = arr[temp];
      max_pos = temp;
    }
  }
  cout << max_pos;
  return 0;
}
