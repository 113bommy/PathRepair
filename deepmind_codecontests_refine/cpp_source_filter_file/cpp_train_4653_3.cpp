#include <bits/stdc++.h>
using namespace std;
vector<int> temp;
long long cnt = 0;
void merge(vector<int> &arr, int from, int mid, int to) {
  int ptr1 = from;
  for (int ptr2 = mid; ptr2 < to; ++ptr2) {
    while (ptr1 < mid && arr[ptr1] < arr[ptr2]) ++ptr1;
    cnt += mid - ptr1;
  }
  int i = from, j = mid, c = from;
  while (i < mid && j < to) {
    if (arr[j] < arr[i])
      temp[c] = arr[j], ++j;
    else
      temp[c] = arr[i], ++i;
    ++c;
  }
  while (i < mid) temp[c] = arr[i], ++i, ++c;
  while (j < to) temp[c] = arr[j], ++j, ++c;
  for (int i = from; i < to; ++i) arr[i] = temp[i];
}
void merge_sort(vector<int> &arr, int from, int to) {
  if (to - from < 2) return;
  int mid = from + ((to - from) >> 1);
  merge_sort(arr, from, mid);
  merge_sort(arr, mid, to);
  merge(arr, from, mid, to);
}
void sort(vector<int> &arr) {
  temp = arr;
  merge_sort(arr, 0, arr.size());
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  sort(arr);
  if (cnt % 2 == n % 2)
    cout << "Petr";
  else
    cout << "Um_Nik";
  return 0;
}
