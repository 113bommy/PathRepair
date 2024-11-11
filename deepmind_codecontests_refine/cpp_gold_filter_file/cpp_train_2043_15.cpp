#include <bits/stdc++.h>
int N, K;
int A[100000];
void mergeSort(int l, int r) {
  if (K <= 0) return;
  if (l == r - 1) return;
  int mid = (l + r) / 2;
  std::swap(A[mid - 1], A[mid]);
  K -= 2;
  mergeSort(l, mid);
  mergeSort(mid, r);
}
int main() {
  std::cin >> N >> K;
  if (K % 2 == 0) {
    std::cout << "-1\n";
    return 0;
  }
  --K;
  for (int i = 0; i < N; i++) A[i] = i + 1;
  mergeSort(0, N);
  if (K == 0) {
    std::cout << A[0];
    for (int i = 1; i < N; i++) std::cout << " " << A[i];
    std::cout << "\n";
  } else
    std::cout << "-1\n";
  return 0;
}
