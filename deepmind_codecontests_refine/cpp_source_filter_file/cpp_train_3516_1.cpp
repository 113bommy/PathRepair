#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  int arr[n],x = 0;
  for (int i=0; i<n; i++) {cin >> arr[i]; x ^= arr[i];}
  for (int i=0; i<n; i++) cout << arr[i] ^ x << " "; cout << endl;
}