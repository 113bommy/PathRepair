#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int a = arr[0], b = 0, i = 1, j = n - 1, moves = 1;
    int ateA = a, ateB = 0;
    bool turnA = false;
    while (i <= j) {
      if (!turnA) {
        ateB = 0;
        while (ateB <= ateA && i <= j) {
          b += arr[j];
          ateB += arr[j];
          j--;
        }
      } else {
        ateA = 0;
        while (ateA <= b && i <= j) {
          ateA += arr[i];
          a += arr[i];
          i++;
        }
      }
      moves++;
      turnA = !turnA;
    }
    cout << moves << " " << a << " " << b << endl;
  }
}
