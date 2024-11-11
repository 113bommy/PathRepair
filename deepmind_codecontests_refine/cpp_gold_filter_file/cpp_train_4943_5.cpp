#include <bits/stdc++.h>
using namespace std;
int a[1000], alen;
int readtag() {
  char c1, c2, c3;
  int temp;
  cin >> c1 >> c2 >> c3;
  if (c2 == '/') {
    temp = 1;
    cin >> c3;
  } else {
    temp = 0;
  }
  if (c3 == 'd') {
    cin >> c1;
    return temp + 0;
  }
  if (c3 == 'r') {
    cin >> c1;
    return 2 + temp;
  }
  if (c3 == 'a') {
    cin >> c1 >> c1 >> c1 >> c1;
    return 4 + temp;
  }
}
void readtable() {
  int col = 0;
  int i;
  int j = alen;
  alen++;
  do {
    i = readtag();
    if (i == 0) {
      a[j]++;
    }
    if (i == 4) {
      readtable();
    }
  } while (i != 5);
}
void qsort(int first, int last) {
  int i = first, j = last, x = a[(i + j) / 2];
  do {
    while (a[i] < x) {
      i++;
    }
    while (a[j] > x) {
      j--;
    }
    if (i <= j) {
      if (i != j) {
        swap(a[i], a[j]);
      }
      i++;
      j--;
    }
  } while (i <= j);
  if (i < last) {
    qsort(i, last);
  }
  if (j > first) {
    qsort(first, j);
  }
}
int main() {
  alen = 0;
  readtag();
  readtable();
  qsort(0, alen - 1);
  for (int i = 0; i < alen; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
