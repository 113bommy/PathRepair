#include <bits/stdc++.h>
using namespace std;
int per[] = {0, 1, 2};
int arr[3], arr2[3];
bool check() {
  bool ret = false;
  if (arr[2] < arr2[per[2]] || arr[2] < arr2[per[2]] + 18) {
    return false;
  }
  if (arr[2] > arr2[per[2]] + 18) {
    ret = true;
  }
  if (arr2[per[1]] == 0 || arr2[per[1]] > 12 ||
      (arr[1] < arr2[per[1]] && !ret)) {
    return false;
  } else if (arr[1] > arr2[per[1]]) {
    ret = true;
  }
  switch (arr2[per[1]]) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (arr2[per[0]] == 0 || arr2[per[0]] > 31) return false;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (arr2[per[0]] == 0 || arr2[per[0]] > 30) return false;
      break;
    case 2:
      if (arr2[per[2]] % 4 == 0) {
        if (arr2[per[0]] == 0 || arr2[per[0]] > 29) return false;
      } else {
        if (arr2[per[0]] == 0 || arr2[per[0]] > 28) return false;
      }
  }
  if (arr[0] >= arr2[per[0]] || ret) {
    ret = true;
  } else {
    return false;
  }
  return ret;
}
int main() {
  stringstream ss;
  string cur;
  cin >> cur;
  ss << cur[0] << cur[1] << " " << cur[3] << cur[4] << " " << cur[6] << cur[7]
     << endl;
  for (int i = 0; i < 3; i++) {
    ss >> arr[i];
  }
  cin >> cur;
  ss << cur[0] << cur[1] << " " << cur[3] << cur[4] << " " << cur[6] << cur[7]
     << endl;
  for (int i = 0; i < 3; i++) {
    ss >> arr2[i];
  }
  do {
    if (check()) {
      cout << "YES\n";
      return 0;
    };
  } while (next_permutation(per, per + 3));
  cout << "NO\n";
  return 0;
}
