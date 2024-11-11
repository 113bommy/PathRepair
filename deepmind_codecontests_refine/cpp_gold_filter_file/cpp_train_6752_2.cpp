#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int G=A+B-C;
  int F=A+G-C;
  int I=B+C-G;
  int go=A+C+I;
  int D=go-A-B;
  int E=go-C-F;
  int H=go-G-I;
  cout<<A<<" "<<B<<" "<<D<<endl;
  cout<<E<<" "<<C<<" "<<F<<endl;
  cout<<G<<" "<<H<<" "<<I<<endl;
}
