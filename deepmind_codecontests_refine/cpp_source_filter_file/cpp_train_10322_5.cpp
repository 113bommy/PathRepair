#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> arr;
  int count, ans, temp;
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  count--;
  ans = 1 - arr[count];
  while (arr[count] != ans) {
    count--;
  }
  cout << count;
}
