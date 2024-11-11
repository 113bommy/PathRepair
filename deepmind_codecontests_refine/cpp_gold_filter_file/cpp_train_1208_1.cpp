#include <bits/stdc++.h>
using namespace std;
int search(int* a, int k) {
  int l = 0, r = 600;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == k) {
      ans = mid;
      break;
    } else if (a[mid] < k) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  int* a = new int[601];
  for (int i = 0; i <= 600; i++) {
    a[i] = (i * (i + 1)) / 2;
  }
  int j = 0;
  int ans[26];
  for (int i = 0; i < 26; i++) {
    ans[i] = 0;
  }
  while (k > 0) {
    int index = search(a, k);
    k = k - a[index];
    ans[j] = index;
    j++;
  }
  string fin = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < ans[i] + 1; j++) {
      fin += (char)(i + 'a');
    }
  }
  cout << fin << endl;
}
