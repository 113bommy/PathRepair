#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  bool pet = true;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] != -1) continue;
    pet = !pet;
    int j = i;
    while (j != -1) {
      int x = arr[j];
      arr[j] = -1;
      j = x;
    }
  }
  if (pet)
    cout << "Petr";
  else
    cout << "Um_nik";
  return 0;
}
