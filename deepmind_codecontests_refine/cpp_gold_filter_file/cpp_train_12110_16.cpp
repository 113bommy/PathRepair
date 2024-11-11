#include <bits/stdc++.h>
using namespace std;
int arr[101];
int brr[101];
int main() {
  vector<string> v[100];
  string s;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v[i].push_back(s);
    string d = v[i][0];
    for (int i = 0; i < m; i++) {
      if (d[i] - 48 > arr[i]) arr[i] = d[i] - 48;
    }
  }
  string d;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      d = v[j][0];
      if (d[i] == arr[i] + 48) brr[j]++;
    }
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (brr[i] > 0) c++;
  }
  cout << c << endl;
}
