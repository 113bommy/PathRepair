#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[100005];
  int min = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < min) min = arr[i];
  }
  int pos[100005];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == min) {
      pos[j] = i;
      j++;
    }
  }
  min = 1e9;
  for (int i = 0; i < j - 1; i++) {
    if (abs(pos[i] - pos[i + 1] < min)) min = abs(pos[i] - pos[i + 1]);
  }
  cout << min << endl;
}
int main() { solve(); }
