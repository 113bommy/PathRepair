#include <bits/stdc++.h>
using namespace std;
void exch(int* a, int* b) {
  int* temp;
  temp = a;
  a = b;
  b = temp;
}
void selection(int* a, int len) {
  for (int i = 0; i < len - 1; i++) {
    int min = i;
    for (int j = i + 1; j < len; j++) {
      if (a[j] > a[min]) min = j;
    }
    if (min != i) {
      int temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
}
int main() {
  int fs, ds, rs;
  cin >> fs;
  cin >> ds;
  cin >> rs;
  char* lal;
  lal = new char[100];
  cin.getline(lal, 100, '\n');
  char* uk;
  int num;
  int* ultra_array;
  ultra_array = new int[fs];
  for (int i = 0; i < fs; i++) {
    cin >> ultra_array[i];
  }
  selection(ultra_array, fs);
  int z = 0;
  while ((ds > rs) && (z < fs)) {
    rs += ultra_array[z];
    rs--;
    z++;
  }
  if (z < fs) {
    cout << z;
  } else {
    cout << -1;
  }
  return 0;
}
