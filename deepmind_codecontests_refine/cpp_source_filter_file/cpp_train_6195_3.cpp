#include <bits/stdc++.h>
using namespace std;
long long int v[4005];
long long int d[4005];
long long int p[4005];
long long int arr[4005];
int main() {
  long long int n, i, j;
  set<long long int> se;
  vector<long long int> ve;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> v[i] >> d[i] >> p[i];
  }
  long long int till = v[0];
  se.insert(v[0]);
  int gone = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == 1) {
      continue;
    }
    if (p[i] >= 0) {
      ve.push_back(i + 1);
    }
    till = v[i];
    long long int counter = v[i];
    for (j = i + 1; j < n; j++) {
      if (arr[j] == 1) continue;
      p[j] -= till;
      if (p[j] < 0) {
        till = till + d[j];
        counter--;
        if (counter > 0) till--;
        arr[j] = 1;
      } else {
        counter--;
        if (counter > 0) till--;
      }
    }
  }
  cout << ve.size() << endl;
  for (i = 0; i < ve.size(); i++) {
    cout << ve[i] << " ";
  }
}
