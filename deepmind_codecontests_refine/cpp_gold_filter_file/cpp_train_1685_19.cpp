#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long int cont = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] <= mn)
        mn = arr[i];
      else
        cont++;
    }
    cout << cont << endl;
  }
}
