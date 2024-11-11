#include <bits/stdc++.h>
using namespace std;

int main(){
  int W,A,B;
  cin>>W>>A>>B;
  cout<<max(max(A,B)-(min(A,B)+w),0)<<endl;
}