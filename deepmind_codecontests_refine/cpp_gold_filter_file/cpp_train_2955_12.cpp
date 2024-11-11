#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> mas(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &mas[i]);
  }
  int index;
  int minIndex = 0;
  for (index = 1; index < n; index++) {
    if (mas[index] <= mas[minIndex]) {
      minIndex = index;
    } else {
      break;
    }
  }
  int maxIndex = index;
  for (index; index < n; index++) {
    if (mas[index] >= mas[maxIndex]) {
      maxIndex = index;
    } else {
      break;
    }
  }
  for (index; index < n; index++) {
    if (mas[index] < mas[maxIndex]) {
      printf("3\n%d %d %d", minIndex + 1, maxIndex + 1, index + 1);
      return 0;
    }
  }
  maxIndex = 0;
  for (index = 1; index < n; index++) {
    if (mas[index] >= mas[maxIndex]) {
      maxIndex = index;
    } else {
      break;
    }
  }
  minIndex = index;
  for (index; index < n; index++) {
    if (mas[index] <= mas[minIndex]) {
      minIndex = index;
    } else {
      break;
    }
  }
  for (index; index < n; index++) {
    if (mas[index] > mas[minIndex]) {
      printf("3\n%d %d %d", maxIndex + 1, minIndex + 1, index + 1);
      return 0;
    }
  }
  printf("0");
  return 0;
}
