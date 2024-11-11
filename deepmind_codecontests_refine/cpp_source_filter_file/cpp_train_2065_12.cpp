#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,B=30;
  cin >> N;
  for(int i=0; i<N; i++){
    int A,C=0;
    cin >> A;
    for(;A%2==0;A/2)
      C++;
    if(C<B)
      B=C;
  }
  cout << A << endl;
}