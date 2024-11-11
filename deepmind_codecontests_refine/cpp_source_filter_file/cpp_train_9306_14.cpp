#include <bits/stdc++.h>
using namespace std;
long long Absolute(long long N) {
  if (N < 0) return -N;
  return N;
};
int main() {
  int Count = 0, i;
  short N;
  long long d, *height;
  cin >> N;
  cin >> d;
  height = new long long[N];
  for (i = 0; i < N; i++) {
    cin >> height[i];
  }
  for (i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (Absolute(height[j] - height[i]) <= d) Count++;
    }
  }
  Count *= 2;
  cout << Count;
  return 0;
}
