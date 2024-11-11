#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1, str2;
  cin >> str1 >> str2;
  string temp = str1;
  int i;
  int n = str1.size();
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  int low = 0;
  int high = n - 1;
  int len2 = str2.size();
  int ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    for (i = 0; i < mid + 1; i++) {
      str1[v[i] - 1] = '\0';
    }
    int j = 0;
    for (i = 0; i < len2;) {
      if (j == n) break;
      if (str2[i] == str1[j]) {
        i++;
        j++;
      } else
        j++;
    }
    if (i == len2) {
      ans = mid + 1;
      low = mid + 1;
    } else if (j == n) {
      high = mid - 1;
    }
    str1 = temp;
  }
  cout << ans << endl;
}
