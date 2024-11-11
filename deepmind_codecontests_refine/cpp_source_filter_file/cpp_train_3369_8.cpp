#include <bits/stdc++.h>
using namespace std;
int C3(int n) { return (n * (n - 1) * (n - 2)) / 6; }
int C2(int n) { return (n * (n - 1)) / 2; }
int main() {
  int k;
  cin >> k;
  int n1;
  for (int i = 1; i <= 90; i++) {
    int num = (i * (i - 1) * (i - 2)) / 6;
    if (num <= k)
      n1 = i;
    else
      break;
  }
  int lft = k - C3(n1);
  vector<int> lens;
  while (lft > 0) {
    int n2;
    for (int i = 1; i <= 90; i++) {
      int num = (i * (i - 1)) / 2;
      if (num <= lft)
        n2 = i;
      else
        break;
    }
    lens.push_back(n2);
    lft -= C2(n2);
  }
  int arr[n1 + lens.size() + 1][n1 + lens.size() + 1];
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n1; j++) {
      if (i == j)
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
    }
  }
  for (int i = (n1 + 1); i <= (n1 + lens.size()); i++) {
    int ind = i - (n1 + 1);
    for (int j = 1; j <= (n1 + lens.size()); j++) {
      if (j <= lens[ind])
        arr[i][j] = 1;
      else
        arr[i][j] = 0;
      arr[j][i] = arr[i][j];
    }
  }
  cout << n1 + lens.size() << endl;
  for (int i = 1; i <= n1 + lens.size(); i++) {
    for (int j = 1; j <= n1 + lens.size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
