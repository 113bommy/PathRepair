#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3];
  arr[0] = arr[1] = arr[2] = 0;
  int x = 0, var;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> var;
    arr[x] += var;
    x++;
    if (x == 3) x = 0;
  }
  int c = 0;
  if (arr[0] > arr[1] && arr[0] > arr[2])
    cout << "chest" << endl;
  else if (arr[1] > arr[0] && arr[1] > arr[2])
    cout << "biceps" << endl;
  else
    cout << "back" << endl;
  return 0;
}
