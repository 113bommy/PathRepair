#include <algorithm> 
#include <iostream> 
using namespace std;
long long int N,a[100000],b,c,d;
int main(){
cin>>N;
for(int i=0;i<N;i++){
cin>>a[i];
if(a[i]%2==1){
b++;
}else{
if(a[i]%4==0){
c++;
}else{
d++;
}
}
}
if(d<=1){
if(c>=b+d-1){
cout<<"Yes"<<endl;
}else{
cout<<"No"<<endl;
}
}else{
if(c>=a){
cout<<"Yes"<<endl;
}else{
cout<<"No"<<endl;
}
}
}