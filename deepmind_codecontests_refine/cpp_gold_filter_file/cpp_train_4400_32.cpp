#include <bits/stdc++.h>
using namespace std;
int main() {
  int petyaFriends = 0;
  int n = 0;
  int result[20000];
  cin >> petyaFriends;
  for (int i = 1; i <= petyaFriends; i++) {
    cin >> n;
    result[n] = i;
  }
  for (int i = 1; i <= petyaFriends; i++) cout << result[i] << " ";
  return 0;
}
