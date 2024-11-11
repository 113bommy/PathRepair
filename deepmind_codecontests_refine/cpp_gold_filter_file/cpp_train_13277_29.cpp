#include <bits/stdc++.h>
using namespace std;
int arr[100000], a, cnt;
int main() {
  cin >> a;
  for (int i = 0; i < a; i++) cin >> arr[i];
  sort(arr, arr + a);
  for (int i = 0; i < a; i++)
    if (arr[i] > cnt) cnt++;
  cout << cnt + 1;
}
