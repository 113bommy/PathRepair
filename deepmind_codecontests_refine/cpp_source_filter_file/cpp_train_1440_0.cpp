#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X;
  cin >>N>>X;
  int s = 0;
  int mi = 200000;
  for(int i=0;i<N;i++){
    int a;
    cin >>a;
    mi = min(mi,a)
    X -= a
  }
  cout << N+X/mi << endl;
}
  