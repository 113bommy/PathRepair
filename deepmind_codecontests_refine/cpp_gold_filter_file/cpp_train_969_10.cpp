#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  int number;
  int arr[1000];
  int min = 10000;
  int max = 0;
  int i;
  int counter = 0;
  for (i = 0; i < test; i++) {
    cin >> number;
    arr[i] = number;
  }
  max = arr[0];
  min = arr[0];
  for (int j = 0; j < test; j++) {
    if (arr[j] > max) {
      max = arr[j];
      counter++;
    }
    if (arr[j] < min) {
      min = arr[j];
      counter++;
    }
  }
  cout << counter << endl;
  return 0;
}
