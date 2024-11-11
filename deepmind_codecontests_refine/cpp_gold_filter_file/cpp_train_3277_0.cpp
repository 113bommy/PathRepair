#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, a;
  cin >> s;
  scanf("%d", &n);
  int arr[100005] = {};
  int x = s.length();
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    arr[a]++;
  }
  for (int i = 1; i <= x / 2; i++) {
    arr[i] += arr[i - 1];
    if (arr[i] % 2) swap(s[i - 1], s[x - i]);
  }
  cout << s;
}
