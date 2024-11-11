#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int N, A;
double sum;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A;
    sum += A;
  }
  cout << sum / N << endl;
}
