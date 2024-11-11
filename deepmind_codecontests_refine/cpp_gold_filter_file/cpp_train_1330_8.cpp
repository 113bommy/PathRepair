#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  int s=N%10;
  if(s==3) cout<<"bon"<<endl;
  else if(s==0||s==1||s==6||s==8) cout<<"pon"<<endl;
  else cout<<"hon"<<endl;
}
