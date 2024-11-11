#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], mony = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mony = mony + arr[i];
  }
  for (int i = 0; i < n; i++) {
    int swch;
    for (int k = i + 1; k < n; k++) {
      if (arr[k] > arr[i]) {
        swch = arr[i];
        arr[i] = arr[k];
        arr[k] = swch;
      }
    }
  }
  int mine = 0, cont = 0, bro = 0;
  for (int i = 0; i < n; i++) {
    mine = mine + arr[i];
    cont++;
    bro = mony - mine;
    if (mine > bro) {
      break;
    }
  }
  cout << cont << endl;
  return 0;
}
