#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> a, const pair<int, int> b) {
  return a.second < b.second;
}
int main() {
  int arr[(int)(3e5 + 50)];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[arr[arr[i]]] == i) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
