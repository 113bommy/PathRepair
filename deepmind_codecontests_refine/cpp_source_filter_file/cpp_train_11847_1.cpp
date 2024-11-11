#include <bits/stdc++.h>
using namespace std;

int main() {
  double int N, A, B;
  cin >> N >> A >> B;
  
  if ( A%2 == B%2 ){
    cout << (B-A)/2 << endl; 
  }
  else {
    cout << min ( (A+B-1)/2 , (2*N-A-B+1)/2 ) << endl;
  }
}
