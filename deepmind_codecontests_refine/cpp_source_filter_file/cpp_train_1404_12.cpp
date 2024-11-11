#include <bits/stdc++.h>
using namespace std;
int k = 0;
struct AB {
  int elem;
  int index;
};
AB A[100];
bool cmp(AB a, AB b) { return a.elem < b.elem; }
int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i].elem;
    A[i].index = i + 1;
  }
  sort(A, A + N, cmp);
  for (int sum = 0; k < N; k++) {
    sum = sum + A[k].elem;
    if (sum > K) {
      break;
    }
  }
  cout << k << endl;
  for (int l = 0; l < k; l++) {
    cout << A[l].elem << " ";
  }
  return 0;
}
