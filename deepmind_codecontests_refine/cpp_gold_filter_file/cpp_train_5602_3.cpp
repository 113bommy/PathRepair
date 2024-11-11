#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,a;
  cin>>A>>B;
  a=max(max(A+A-1,B+B-1),A+B);
  cout<<a<<endl;

}
