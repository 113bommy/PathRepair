#include <bits/stdc++.h>
using namespace std;
int arr[100000], a, cnt = 1;
int main() {
  cin >> a;
  for (int i = 0; i < a; i++) cin >> arr[i];
  sort(arr, arr + a);
  for (int i = 0; i < a; i++)
    if (arr[i] > cnt) cnt++;
  cout << cnt;
}
