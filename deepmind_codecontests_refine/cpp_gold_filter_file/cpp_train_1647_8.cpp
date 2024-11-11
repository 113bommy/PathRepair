#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A[4];
  cin >> A[0] >> A[1] >> A[2] >> A[3];
  sort(A,A+4);
  if (A[0]==1 and A[1]==4 and A[2]==7 and A[3]==9){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
}
