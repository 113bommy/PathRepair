#include <bits/stdc++.h>
using namespace std;
int find1(int arr[], int beg, int end, int key) { return 0; }
int find2(int arr[], int size, int key) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] > key) {
      return i - 1;
    }
  }
  return size - 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int pow2[] = {0,   1,    2,    4,    8,    16,    32,    64,    128,   256,
                512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
  int size;
  cin >> size;
  while (size > 0) {
    int index = find2(pow2, 19, size);
    cout << index << ' ';
    size -= pow2[index];
  }
}
