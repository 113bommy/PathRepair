#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  bool ans=(N%4==0);
  if ((N%4==1&&N>20)||(N%4==2&&N>13)||(N%4==3&&N>6)){
    ans=1;
  }
  cout<<(ans?"Yes":"No")<<endl;
}

