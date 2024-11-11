#include <bits/stdc++.h>
using namespace std;
bool compar(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
bool compar_arr(const int &a, const int &b) { return a > b; }
int main(void) {
  int n;
  cin >> n;
  int a[n];
  vector<pair<int, int> > b;
  for (int i = (0); i < (n); i++) cin >> a[i];
  int temp;
  for (int i = (0); i < (n); i++) {
    cin >> temp;
    b.push_back(make_pair(temp, i));
  }
  sort(a, a + n, compar_arr);
  int k = 0;
  sort(b.begin(), b.end(), compar);
  int x[n];
  for (int i = (0); i < (n); i++) {
    x[b[i].second] = a[k++];
  }
  for (int i = (0); i < (n); i++) cout << x[i] << " ";
  return 0;
}
