#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  cout << N * (N-1) / 2 - N / 2 << endl;
  for (int i=1; i<=N-1 ;i++) {
    for (int j=i+1; j<=N; j++) {
      if (i+j != N + (N+1) % 2) {
        cout << i << " " << j << endl;
      }
    }
  }
  
}
