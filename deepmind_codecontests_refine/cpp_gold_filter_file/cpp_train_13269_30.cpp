#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int no = 1e6;
  int n;
  cin >> n;
  int arr[no];
  for (int(i) = 0; (i) < (no); (i)++) {
    arr[i] = 0;
  }
  int array[n + 1];
  for (int(i) = 0; (i) < (n); (i)++) {
    long long int a;
    cin >> a;
    array[i] = a;
    arr[a]++;
  }
  long long int temp = -1;
  for (int(i) = (1); (i) <= (no - 2); (i)++) {
    if (arr[i] < arr[i + 1]) {
      temp = 1;
      cout << -1 << endl;
      break;
    }
  }
  if (temp == -1) {
    cout << arr[1] << endl;
    for (int(i) = 0; (i) < (n); (i)++) {
      cout << arr[array[i]] << " ";
      arr[array[i]]--;
    }
    cout << endl;
  }
}
