#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++) {
      cin >> arr[i];
    }
    int moves = 0;
    for (int i = 0; i < a; i++) {
      if (arr[i] == 1) {
        for (int j = i + 1; j < a; j++) {
          if (arr[j] == 1) {
            moves += j - i - 1;
            i = j;
            break;
          }
        }
      }
    }
    cout << moves << endl;
  }
}
