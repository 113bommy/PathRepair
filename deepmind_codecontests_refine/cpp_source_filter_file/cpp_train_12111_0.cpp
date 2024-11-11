#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  long long N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  sort(arr, arr + N);
  for (int i = 0; i < N; i++) {
    long long count = 0;
    for (int j = i; arr[j] == arr[i]; j++, count++)
      ;
    if (K > count * N)
      K -= count * N;
    else {
      cout << arr[i] << " " << arr[K / count + K % count - 1] << endl;
      break;
    }
    i += (count - 1);
  }
  return 0;
}
