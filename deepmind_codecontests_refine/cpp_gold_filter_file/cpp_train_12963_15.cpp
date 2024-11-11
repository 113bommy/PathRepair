#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, ans;
  cin >> n;
  int hash[367][2];
  for (i = 0; i < 367; i++) {
    hash[i][0] = 0;
    hash[i][1] = 0;
  }
  for (j = 0; j < n; j++) {
    char sex;
    int start, end;
    cin >> sex >> start >> end;
    if (sex == 'F') {
      for (i = start; i <= end; i++) hash[i][0] += 1;
    } else {
      for (i = start; i <= end; i++) hash[i][1] += 1;
    }
  }
  ans = INT_MIN;
  for (i = 0; i < 367; i++) {
    long long int temp = (hash[i][0] <= hash[i][1]) ? hash[i][0] : hash[i][1];
    if (temp > ans) ans = temp;
  }
  cout << ans * 2 << endl;
  return 0;
}
