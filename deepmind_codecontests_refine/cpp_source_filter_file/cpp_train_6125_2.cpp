#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  if(A+B-C-D<0)cout<<"Right"<<endl;
  else if(A+B-C-D=0)cout<<"Balanced"<<endl;
  else cout<<"Left"<<endl;
  
}
