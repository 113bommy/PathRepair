#include <bits/stdc++.h>
using namespace std;
int ar[100005] = {0};
void seive() {
  for (int i = 2; i <= 100000; i++) {
    if (ar[i] == 0) {
      for (int j = i * 2; j <= 100000; j = j + i) {
        ar[j] = 1;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  seive();
  if (n <= 2) {
    cout << 1 << endl;
    ;
    for (int i = 2; i <= n + 1; i++) {
      cout << ar[i] + 1 << " ";
    }
    cout << endl;
  } else {
    cout << 2 << endl;
    for (int i = 2; i <= n + 1; i++) {
      cout << ar[i] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
