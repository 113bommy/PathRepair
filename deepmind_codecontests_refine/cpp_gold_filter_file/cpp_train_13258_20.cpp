#include <bits/stdc++.h>
using namespace std;
struct TARR {
  int *m_Arr;
};
int cmpFunc(const void *a, const void *b) {
  TARR u = *(TARR *)a;
  TARR v = *(TARR *)b;
  return (u.m_Arr[0] - v.m_Arr[0]);
}
int main(void) {
  int s = 0, n = 0;
  cin >> s >> n;
  TARR *arr = new TARR[n];
  for (int i = 0; i < n; i++) arr[i].m_Arr = new int[2];
  for (int i = 0; i < n; i++) cin >> arr[i].m_Arr[0] >> arr[i].m_Arr[1];
  qsort(arr, n, sizeof(int *), cmpFunc);
  for (int i = 0; i < n; i++) {
    if (s <= arr[i].m_Arr[0]) {
      cout << "NO" << endl;
      return 0;
    } else {
      s += arr[i].m_Arr[1];
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) delete[](arr[i].m_Arr);
  delete[] arr;
  return 0;
}
