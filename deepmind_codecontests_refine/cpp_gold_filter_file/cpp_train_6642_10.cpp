#include<iostream>
using namespace std;
int main(){
  int a,f,s;
  cin>>a;
  f=a/100;
  s=a%100;
 if((1<=f&&f<=12)&&(s>=1&&s<=12)){
   cout<<"AMBIGUOUS"<<endl;
 }else if(1<=s&&s<=12){
   cout<<"YYMM"<<endl;
 }else if(1<=f&&f<=12){
   cout<<"MMYY"<<endl;
 }else{
   cout<<"NA"<<endl;
 }
   return 0;
}
