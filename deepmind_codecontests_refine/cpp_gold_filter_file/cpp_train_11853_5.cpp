#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,i;
  cin>>H>>W;
  for(i=0;i<W+2;i++)cout<<"#";
  cout<<endl;
  for(i=0;i<H;i++){
    string S;
    cin>>S;
    S="#"+S+"#";
    cout<<S<<endl;
  }
   for(i=0;i<W+2;i++)cout<<"#";
  cout<<endl;
}
