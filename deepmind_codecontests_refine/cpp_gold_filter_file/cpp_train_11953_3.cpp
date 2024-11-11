#include<iostream>
#include<string>
using namespace std;
int main() {
  int N;
  string A,B,C;
  cin >>N>>A>>B>>C;
  int x=0;
  for (int i=0;i<N;i++){
    if(A[i]==B[i]&&B[i]==C[i])continue;
    if(A[i]==B[i]||B[i]==C[i]||C[i]==A[i])x++;
    else x+=2;
  }
  cout<<x<<endl;
}
