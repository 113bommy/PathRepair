#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(100005);
  vector<int> arr2(100005);
  int a;
  int answer = 1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[a]++;
    arr2[arr[a]]++;
    if (arr2[arr[a]] * arr[a] == (i + 1) && i < n - 1) {
      answer = i + 2;
    }
    if (arr2[arr[a]] * arr[a] == i) {
      answer = i + 1;
    }
  }
  cout << answer << "\n";
  return 0;
}
