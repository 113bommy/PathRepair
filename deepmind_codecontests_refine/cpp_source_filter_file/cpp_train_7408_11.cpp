#include <bits/stdc++.h>
using namespace std;
void swwap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int bbinary_search(int val, int low, int high, vector<pair<int, int> > vec) {
  int mid = (low + high) / 2;
  while (low < high) {
    if (vec[mid].first == val)
      return mid;
    else if (vec[mid].first > val)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}
void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    int k = n / 2;
    long long int ans = 1;
    for (int i = 0; i < k; i++) {
      ans = ans << 1;
    }
    cout << ans << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
