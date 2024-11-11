#include<iostream>
using namespace std;
     
int main()
{
int L,A,B,C,D,K,E,F;
cin>>L>>A>>B>>C>>D;
E=A/C;
F=B/D;
if(A%C>0){
E+=1;
}
if(B%D>0){
F+=1;
}
if(E<F){
K=L-E;
}
else(E>F)
K=L-F;
cout<<K<<'\n';
return 0;
}