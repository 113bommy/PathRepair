#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int one = 0, two = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      one++;
    } else {
      two++;
    }
  }
  int prime = 0;
  while (one != 0 && two != 0) {
    if (prime == 0 && two > 0) {
      prime = 2;
      two--;
      cout << 2 << " ";
      continue;
    } else if (prime == 0 && one > 0) {
      prime = 1;
      one--;
      cout << 1 << " ";
      continue;
    }
    if (prime == 1 && one > 0) {
      prime = 2;
      one--;
      cout << 1 << " ";
      continue;
    } else if (prime == 1 && two > 0) {
      prime = 3;
      two--;
      cout << 2 << " ";
      continue;
    }
    if (prime == 2 && one > 0) {
      prime = 3;
      one--;
      cout << 1 << " ";
      continue;
    }
    if (two > 0) {
      prime += 2;
      two--;
      cout << 2 << " ";
    } else {
      prime += 1;
      one--;
      cout << 1 << " ";
    }
  }
  return 0;
}
