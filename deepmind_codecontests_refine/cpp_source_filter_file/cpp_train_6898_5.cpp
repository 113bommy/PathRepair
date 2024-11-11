#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] < arr[j + 1]) swap(&arr[j], &arr[j + 1]);
}
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}
int main() {
  int cases;
  string s;
  cin >> cases;
  while (cases--) {
    cin >> s;
    int i = 0;
    int full = 0;
    int ones[100];
    int one = 0;
    int j = 0;
    for (int o = 0; o < s.length(); o++) {
      if (s[o] != '1') break;
      full++;
    }
    if (full == s.length()) {
      cout << s.length() / 2 << endl;
    } else {
      for (; i < s.length(); i++) {
        if (s[i] == '0') {
          ones[j] = one;
          one = 0;
          j++;
        } else
          one++;
      }
      ones[j++] = one;
      bubbleSort(ones, j);
      int out = 0;
      for (int k = 0; k < j - 1; k += 2) {
        out += ones[k];
      }
      cout << out << endl;
    }
  }
}
