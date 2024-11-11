#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int& x : A) cin >> x, --x;
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (i == A[A[i]]);
  }
  cout << ans / 2 << endl;
}