#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  set<int> degree[20];
  cin >> n >> m;
  vector<int> a(n + 1);
  set<int>::iterator it;
  for (int j = 0; j < 20; j++) {
    degree[j].insert(0);
    degree[j].insert(n + 1);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 20; j++)
      if ((a[i] & (1 << j)) == 0) degree[j].insert(i);
  }
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 20; j++) {
      if (a[i] & (1 << j)) {
        it = degree[j].upper_bound(i);
        long long int pos = *it;
        sum += (pos - i) * (1 << j);
      }
    }
  }
  for (int k = 0; k < m; k++) {
    int i, x;
    cin >> i >> x;
    for (int j = 0; j < 20; j++) {
      if ((a[i] & (1 << j)) == 0 && (x & (1 << j))) {
        it = degree[j].find(i);
        it++;
        long long int posfin = *it;
        it--;
        it--;
        long long int posini = *it;
        sum += (posfin - i) * (1 << j) * (i - posini);
        degree[j].erase(i);
      } else if ((a[i] & (1 << j)) && (x & (1 << j)) == 0) {
        degree[j].insert(i);
        it = degree[j].find(i);
        it++;
        long long int posfin = *it;
        it--;
        it--;
        long long int posini = *it;
        sum -= (posfin - i) * (1 << j) * (i - posini);
      }
    }
    a[i] = x;
    cout << sum << endl;
  }
}
