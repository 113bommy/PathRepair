#include <bits/stdc++.h>
using namespace std;
string oleg_s, ihor_s;
int *oleg_indexes, *ihor_indexes, *oleg_arr, *ihor_arr;
vector<bool> used;
void quickSort(int *a, int *indexes, int l, int r) {
  int x = a[l + (r - l) / 2];
  int i = l;
  int j = r;
  while (i <= j) {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (i < r) quickSort(a, indexes, i, r);
  if (l < j) quickSort(a, indexes, l, j);
}
int main() {
  cin >> oleg_s;
  cin >> ihor_s;
  used.resize(oleg_s.size(), 0);
  oleg_arr = new int[oleg_s.size()];
  ihor_arr = new int[ihor_s.size()];
  oleg_indexes = new int[oleg_s.size()];
  ihor_indexes = new int[ihor_s.size()];
  for (int i = 0; i < oleg_s.size() && i < ihor_s.size(); i++) {
    oleg_arr[i] = (int)oleg_s[i] - 48;
    ihor_arr[i] = (int)ihor_s[i] - 48;
    oleg_indexes[i] = i;
    ihor_indexes[i] = i;
  }
  quickSort(oleg_arr, oleg_indexes, 0, oleg_s.size() - 1);
  quickSort(ihor_arr, ihor_indexes, 0, ihor_s.size() - 1);
  int index = 0, oleg_ind = 0, ihor_ind = ihor_s.size() - 1;
  int oleg_check_ind = (ihor_s.size() + 1) / 2,
      ihor_check_ind = (oleg_s.size() - 1) / 2,
      oleg_mid = (oleg_s.size() - 1) / 2, ihor_mid = (ihor_s.size() + 1) / 2;
  int min_for_oleg = 0, max_for_egor = oleg_s.size() - 1;
  int front_ind = 0, end_ind = ihor_s.size() - 1;
  string result;
  result.resize(oleg_s.size());
  while (index < oleg_s.size()) {
    if (index % 2 == 0) {
      if (ihor_arr[ihor_indexes[ihor_ind]] >= oleg_arr[oleg_indexes[oleg_ind]])
        result[front_ind++] = (char)(oleg_arr[oleg_indexes[oleg_ind++]] + 48);
      else
        result[end_ind--] = (char)(oleg_arr[oleg_indexes[oleg_mid--]] + 48);
    } else {
      if (oleg_arr[oleg_indexes[oleg_ind]] < ihor_arr[ihor_indexes[ihor_ind]])
        result[front_ind++] = (char)(ihor_arr[ihor_indexes[ihor_ind--]] + 48);
      else
        result[end_ind--] = (char)(ihor_arr[ihor_indexes[ihor_mid++]] + 48);
    }
    index++;
  }
  cout << result;
  return 0;
}
