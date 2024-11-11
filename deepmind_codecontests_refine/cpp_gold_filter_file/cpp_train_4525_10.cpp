#include <bits/stdc++.h>
using namespace std;
inline void fastread(int* a) {
  register char c = 0;
  while (c < 33) c = getchar();
  *a = 0;
  while (c > 33) {
    *a = *a * 10 + c - '0';
    c = getchar();
  }
}
inline void Merge(int array[][2], int left, int mid, int right) {
  int tempArray[right - left + 1][2];
  int pos = 0, lpos = left, rpos = mid + 1;
  while (lpos <= mid && rpos <= right) {
    if (array[lpos][1] < array[rpos][1]) {
      tempArray[pos][0] = array[lpos][0];
      tempArray[pos++][1] = array[lpos++][1];
    } else {
      tempArray[pos][0] = array[rpos][0];
      tempArray[pos++][1] = array[rpos++][1];
    }
  }
  while (lpos <= mid) {
    tempArray[pos][0] = array[lpos][0];
    tempArray[pos++][1] = array[lpos++][1];
  }
  while (rpos <= right) {
    tempArray[pos][0] = array[rpos][0];
    tempArray[pos++][1] = array[rpos++][1];
  }
  int iter;
  for (iter = 0; iter < pos; iter++) {
    array[iter + left][0] = tempArray[iter][0];
    array[iter + left][1] = tempArray[iter][1];
  }
  return;
}
inline void MergeSort(int array[][2], int left, int right) {
  int mid = (left + right) / 2;
  if (left < right) {
    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);
    Merge(array, left, mid, right);
  }
  return;
}
int main() {
  int i, n;
  cin >> n;
  int a[n + 1][2];
  int range[2001] = {0};
  for (i = 1; i <= n; i++) {
    cin >> a[i][1];
    a[i][0] = i;
    range[a[i][1]]++;
  }
  int m1 = -1, m2 = -1;
  int temp = -1;
  for (int i = 0; i <= 2000; i++) {
    if (m1 < range[i]) {
      m1 = range[i];
      temp = i;
    }
  }
  int temp2 = -1;
  for (int i = 0; i <= 2000; i++) {
    if (m2 < range[i] && i != temp) {
      m2 = range[i];
      temp2 = i;
    }
  }
  MergeSort(a, 1, n);
  if (m1 >= 3 || m2 >= 2) {
    cout << "YES\n";
    if (m1 == 2) {
      for (int i = 1; i <= n; i++) cout << a[i][0] << " ";
      cout << endl;
      for (int i = 1; i <= n; i++) {
        if (a[i][1] != temp)
          cout << a[i][0] << " ";
        else {
          cout << a[i + 1][0] << " " << a[i][0] << " ";
          i++;
        }
      }
      cout << endl;
      for (int i = 1; i <= n; i++) {
        if (a[i][1] != temp2)
          cout << a[i][0] << " ";
        else {
          cout << a[i + 1][0] << " " << a[i][0] << " ";
          i++;
        }
      }
    } else if (m1 > 2) {
      int flag = 1;
      for (int i = 1; i <= n; i++) cout << a[i][0] << " ";
      cout << endl;
      for (int i = 1; i <= n; i++) {
        if (a[i][1] != temp || flag == 0)
          cout << a[i][0] << " ";
        else {
          cout << a[i + 1][0] << " " << a[i][0] << " ";
          i++;
          flag = 0;
        }
      }
      cout << endl;
      flag = 1;
      for (int i = 1; i <= n; i++) {
        if (a[i][1] != temp || flag == 0)
          cout << a[i][0] << " ";
        else {
          cout << a[i + 2][0] << " " << a[i + 1][0] << " " << a[i][0] << " ";
          i++;
          i++;
          flag = 0;
        }
      }
      cout << endl;
    }
  } else
    cout << "NO\n";
  return 0;
}
