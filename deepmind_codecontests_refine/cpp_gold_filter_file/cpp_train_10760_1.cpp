#include <bits/stdc++.h>
using namespace std;
bool taken[1000];
int choices[30], n, k;
int main() {
  cin >> n >> k;
  for (size_t i = 0; i < k; i++) {
    cin >> choices[i];
    taken[choices[i]] = true;
  }
  for (size_t i = 0; i < k; i++) {
    int left = n - 1;
    cout << choices[i];
    for (size_t j = 1; j < 1000 && left; j++) {
      if (!taken[j]) {
        cout << " " << j;
        taken[j] = true;
        left--;
      }
    }
    cout << endl;
  }
  return 0;
}
