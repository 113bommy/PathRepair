#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << "YES\n1\n" << arr[0] << endl << "0";
    return 0;
  }
  sort(arr, arr + n);
  vector<int> up;
  vector<int> down;
  for (int i = 0; i < n; i++) {
    if (i % 2)
      up.push_back(arr[i]);
    else
      down.push_back(arr[i]);
  }
  for (int i = 0; i < up.size() - 1; i++) {
    if (up[i] == up[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i < down.size() - 1; i++) {
    if (down[i] == down[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << up.size() << endl;
  for (int i = 0; i < up.size(); i++) {
    cout << up[i] << ' ';
  }
  cout << endl << down.size() << endl;
  reverse(down.begin(), down.end());
  for (int i = 0; i < down.size(); i++) {
    cout << down[i] << ' ';
  }
}
