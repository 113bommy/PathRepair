#include <bits/stdc++.h>
using namespace std;
int n, el, k = 0;
int arr[100045];
void seive() {
  for (int i = 2; i * i < 100012; i++) {
    if (arr[i])
      continue;
    else
      for (int j = 2 * i; j < 100012; j += i) arr[j] = 1;
  }
}
int main() {
  seive();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int input[100060] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> el;
    input[el] += 1;
  }
  int ans = 1;
  for (int i = 2; i < 100012; i++) {
    if (arr[i]) continue;
    int temp = 0;
    for (int j = i; j < 100012; j += i) temp += input[j];
    ans = max(ans, temp);
  }
  cout << ans;
}
