#include <bits/stdc++.h>
using namespace std;
int N;
bool A[2000];
int main() {
  cin >> N;
  int top = 0;
  for (int i = 1; top <= 500; i++) {
    top += i;
    A[top] = true;
  }
  if (A[N])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
