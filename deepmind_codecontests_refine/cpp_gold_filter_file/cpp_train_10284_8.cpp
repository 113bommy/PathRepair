#include<bits/stdc++.h>
using namespace std;
int main(){
int K,A,B;
cin>>K>>A>>B;
int a=K*(((A-1)/K)+1);
if(a<=B)
cout<<"OK"<<endl;
else
cout<<"NG"<<endl;
   return 0;
}