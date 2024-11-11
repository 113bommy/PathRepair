#include <bits/stdc++.h>
using namespace std;
int strcmp(char a[], char b[]) {
  int i, count2 = 0;
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      count2++;
    }
  }
  return count2;
}
int main() {
  int n, i, j, count1[100] = {0}, max = 0;
  char room[101][101];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> room[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      if (strcmp(room[i], room[j]) == 0) {
        count1[i]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (count1[i] > max) {
      max = count1[i];
    }
  }
  if (max == 0) {
    cout << 1;
  } else
    cout << max;
  return 0;
}
