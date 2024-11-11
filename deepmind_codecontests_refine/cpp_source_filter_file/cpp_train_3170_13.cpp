#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count_a = 0, count_b = 0;
  vector<string> arr;
  string temp, other;
  cin >> n;
  for (i = 0; i <= n; i++) {
    getline(cin, temp);
    arr.push_back(temp);
  }
  temp = arr[1];
  count_a = 1;
  for (i = 2; i <= n; i++) {
    if (temp == arr[i])
      count_a++;
    else {
      count_b++;
      other = temp;
    }
  }
  if (count_a > count_b)
    cout << temp;
  else
    cout << other;
  return 0;
}
