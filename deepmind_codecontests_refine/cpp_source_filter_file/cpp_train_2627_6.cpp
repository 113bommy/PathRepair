#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  int final[N];
  final[0] = arr[0];
  int curMax = 0;
  for (int i = 1; i < N; i++) {
    final[i] = arr[i] + curMax;
    curMax = max(curMax, final[i]);
  }
  for (int i = 0; i < N; i++) cout << final[i] << " ";
  cout << endl;
}
