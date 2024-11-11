#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  int a[200000], b[200000];
  bool visited[200001] = {false};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (visited[b[i]]) {
      cout << 0 << " ";
    } else {
      int counter = 0;
      for (int j = index; j < n; j++) {
        if (!visited[a[j]]) counter++;
        visited[a[j]] = true;
        if (a[j] == b[i]) {
          index = j;
          break;
        }
      }
      cout << counter << " ";
    }
  }
}
