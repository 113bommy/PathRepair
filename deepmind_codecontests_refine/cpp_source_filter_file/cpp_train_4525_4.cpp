#include <bits/stdc++.h>
using namespace std;
struct two {
  int num, i;
};
int already = 0;
bool comp(two a, two b) { return a.num < b.num; }
void show(two *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << arr[i].i << " ";
  }
  cout << arr[n - 1].i << endl;
  already++;
}
int main() {
  int n = 0;
  ios::sync_with_stdio(false);
  cin >> n;
  two *arr = new two[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].num;
    arr[i].i = i + 1;
  }
  sort(arr, arr + n, comp);
  int first_two = 0;
  int start = 0;
  int two_cnt = 0;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1].num == arr[i].num) {
      cnt++;
    } else {
      if (cnt == 3) {
        cout << "YES" << endl;
        show(arr, n);
        swap(arr[start], arr[start + 1]);
        show(arr, n);
        swap(arr[start], arr[start + 1]);
        swap(arr[start], arr[start + 2]);
        show(arr, n);
        swap(arr[start], arr[start + 2]);
        return 0;
      }
      if (cnt == 2) {
        if (two_cnt) {
          cout << "YES" << endl;
          show(arr, n);
          swap(arr[first_two], arr[first_two + 1]);
          show(arr, n);
          swap(arr[first_two], arr[first_two + 1]);
          swap(arr[start], arr[start + 1]);
          show(arr, n);
          swap(arr[start], arr[start + 1]);
          return 0;
        }
        first_two = start;
        two_cnt++;
      }
      cnt = 1;
      start = i;
    }
  }
  if (cnt == 3) {
    cout << "YES" << endl;
    show(arr, n);
    swap(arr[start], arr[start + 1]);
    show(arr, n);
    swap(arr[start], arr[start + 1]);
    swap(arr[start], arr[start + 2]);
    show(arr, n);
    swap(arr[start], arr[start + 2]);
    return 0;
  }
  if (cnt == 2) {
    if (two_cnt) {
      cout << "YES" << endl;
      show(arr, n);
      swap(arr[first_two], arr[first_two + 1]);
      show(arr, n);
      swap(arr[first_two], arr[first_two + 1]);
      swap(arr[start], arr[start + 1]);
      show(arr, n);
      swap(arr[start], arr[start + 1]);
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
