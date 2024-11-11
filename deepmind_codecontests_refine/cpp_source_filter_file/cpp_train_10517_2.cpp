#include<iostream>
using namespace std;
int main(){

while(1){
int m,f,r;
cin>>m>>f>>r;
if(m==-1 && f==-1 && r==-1)break;

if(m==-1 || f==-1){
cout<<"F"<<endl;
}else{
int q=m+f;
 if( q>=80 ){
  cout<<"A"<<,endl;
 }else if( q>=65 && q<80 ){
  cout<<"B"<<endl;
 }else if( q>=50 && q<65 ){
  cout<<"C"<<endl;
 }else if( q>=30 && q<50 ){
  if(r>=50)cout<<"C"<<endl;
  if(r<50)cout<<"D"<<endl;
 }else if(q<30){
  cout<<"F"<<endl;
 }
}
}

}

