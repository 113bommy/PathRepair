#include <bits/stdc++.h>
class nd {
 public:
  int a, b;
  nd(int _a = 0, int _b = 0) : a(_a), b(_b) {}
  bool operator<(const nd &rhs) const {
    return ((this->a < rhs.a) || (this->a == rhs.a && this->b < rhs.b));
  }
  nd &operator=(const nd &rhs) {
    a = rhs.a;
    b = rhs.b;
    return *this;
  }
};
int n;
nd *A;
void merge(nd A[], nd B[], int le, int mid, int ri);
void mergeSort(nd A[], nd B[], int le, int ri) {
  if (le < ri) {
    int mid = (le + ri) / 2;
    mergeSort(A, B, le, mid);
    mergeSort(A, B, mid + 1, ri);
    merge(A, B, le, mid, ri);
  }
}
void merge(nd A[], nd B[], int le, int mid, int ri) {
  int lEnd, rEnd, idx;
  lEnd = le;
  rEnd = mid + 1;
  idx = le;
  while (lEnd <= mid && rEnd <= ri) {
    if (A[lEnd] < A[rEnd]) {
      B[idx++] = A[lEnd++];
    } else {
      B[idx++] = A[rEnd++];
    }
  }
  while (lEnd <= mid) B[idx++] = A[lEnd++];
  while (rEnd <= mid) B[idx++] = A[rEnd++];
  for (int i = le; i <= ri; i++) A[i] = B[i];
}
void input() {
  scanf("%d", &n);
  A = new nd[n];
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &A[i].a, &A[i].b);
  }
}
void solve() {
  input();
  nd *B = new nd[n];
  mergeSort(A, B, 0, n - 1);
  int q = 0;
  for (int i = 0; i < n; i++) {
    if (q > A[i].b) {
      puts("Happy Alex");
      return;
    }
    if (q < A[i].b) q = A[i].b;
  }
  puts("Poor Alex");
  delete[] A;
  delete[] B;
}
int main(void) {
  solve();
  return 0;
}
