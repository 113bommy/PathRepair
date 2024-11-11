#include<iostream>
using namespace std;

int Sort(int arr[],int N){
int sw=0;
bool flag=1;
for(int i=0;flag;i++){
flag=0;
for(int j=N-1;j>=i+1;j--){
if(arr[j]<arr[j-1]){
swap(arr[j],arr[j-1]);
flag=1;
sw++;
}
}
}
return sw;
}

int main(){
int arr[100],N,sw;
cin>>N;
for(int i=0;i<N;i++)cin>>arr[i];

sw=Sort(arr,N);
for(int i=0;i<N;i++){
if(i)cout<<" ";
cout<<arr[i];
}
cout<<endl;
cout<<sw<<endl;

return 0;
}