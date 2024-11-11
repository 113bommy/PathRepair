#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> vec;
  int count = 0;
  int N;
  cin >> N;
  int arr[N - 1][2];
  for (int i = 0; i < (N - 1); i++) {
    for (int j = 0; j < 2; j++) {
      cin >> arr[i][j];
    }
  }
  for (int search_item = 1; search_item <= N; search_item++) {
    for (int p = 0; p < (N - 1); p++) {
      for (int q = 0; q < 2; q++) {
        if (arr[p][q] == search_item) {
          count++;
          break;
        }
      }
    }
    if (count == 1) {
      vec.push_back(search_item);
      count -= count;
    } else {
      count -= count;
    }
  }
  cout << vec[1] << "\n";
  return 0;
}
