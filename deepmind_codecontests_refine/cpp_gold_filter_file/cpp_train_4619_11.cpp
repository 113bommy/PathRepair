#include <bits/stdc++.h>
using namespace std;
struct solution {
  bool pet;
  bool vas;
  bool ton;
};
void nh(solution &a) { cin >> a.pet >> a.vas >> a.ton; }
void nhap(solution a[], int n) {
  for (int i = 0; i < n; i++) nh(a[i]);
}
bool kt(solution a) {
  int k = 0;
  if (a.pet == 1) k++;
  if (a.vas == 1) k++;
  if (a.ton == 1) k++;
  if (k >= 2)
    return true;
  else
    return false;
}
int dem(solution a[], int n) {
  int d = 0;
  for (int i = 0; i < n; i++)
    if (kt(a[i]) == true) d++;
  return d;
}
int main() {
  int n;
  cin >> n;
  solution a[n];
  nhap(a, n);
  cout << dem(a, n);
  return 0;
}
