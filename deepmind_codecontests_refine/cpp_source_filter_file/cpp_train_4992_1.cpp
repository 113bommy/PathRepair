#include <algorithm>
#include <iostream>
using namespace std;
int T,N,K,X[100000+10], A[100000+10];

int main(){
 cin >> T;
 for (int t=0; t<T; ++t){
  int Sum;
  cin >> N;
  cin >> K;
  for (int i=0; i<N; ++i)
    cin >> X[i];
  for (int i=0; i+1<N; ++i) A[i] = X[i+1]-X[i];
  sort(A,A+N-1);
  for (int i=0; i<(N-1-(K-1)); ++i)
  Sum += A[i];
  cout << Sum << endl;
  Sum = 0
  }
 } 