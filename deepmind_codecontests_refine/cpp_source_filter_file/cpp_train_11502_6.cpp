#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m = 1;
  int n;
  cin >> n >> m;
  int myints[55];
  for (int i = 1; i <= n; i++) myints[i - 1] = i;
  vector<vector<int> > v;
  do {
    int sum = 0;
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++) {
        int min = myints[i];
        for (int k = i; k <= j; k++)
          if (min > myints[k]) min = myints[k];
        sum += min;
      }
    vector<int> tmp;
    tmp.push_back(sum);
    for (int i = 0; i < n; i++) tmp.push_back(myints[i]);
    v.push_back(tmp);
  } while (next_permutation(myints, myints + n));
  int max = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i][0] > max) max = v[i][0];
  }
  vector<vector<int> > ans;
  for (int i = 0; i < v.size(); i++) {
    if (v[i][0] == max) ans.push_back(v[i]);
  }
  for (int i = 1; i <= n; i++) cout << v[m - 1][i] << ' ';
  return 0;
}
