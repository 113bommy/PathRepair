#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, min = 110, max = -1, minIndex = 0, maxIndex = 0;
  cin >> N;
  int* m = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> m[i];
    if (m[i] > max) {
      max = m[i];
      maxIndex = i;
    }
    if (m[i] < min) {
      min = m[i];
      minIndex = i;
    } else if (m[i] == min) {
      minIndex = i;
    }
  }
  int count = 0;
  if (minIndex < N - 1) {
    count = N - minIndex - 1;
  }
  if (maxIndex > 0) {
    count += maxIndex;
  }
  if (maxIndex > minIndex) {
    count--;
  }
  cout << count << endl;
  return 0;
}
