#include <bits/stdc++.h>
using namespace std;
int arr[1010];
void initialize() {
  for (int i = 1; i <= 1000; i++) arr[i] = 1;
  arr[1] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v;
  int c = 0;
  int first = 0;
  initialize();
  for (int i = 2; i <= n; i++) {
    if (arr[i] == 1) {
      v.push_back(i);
      c++;
      for (int j = i * 2; j <= n; j += i) {
        arr[j] = 0;
      }
      for (int j = i * i; j <= n; j *= i) {
        c++;
        v.push_back(j);
      }
    }
  }
  cout << c << '\n';
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << '\n';
  return 0;
}
