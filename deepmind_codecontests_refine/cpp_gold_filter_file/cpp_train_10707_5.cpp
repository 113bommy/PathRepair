#include<iostream>
#include<map>
using namespace std;
int main(){
 int n,sum=0,a[100000];
 map<int,bool> m={};
 cin>>n;
 for(int i=0;i<n;i++){
  cin>>a[i];
  if(!m[a[i]]){
    m[a[i]]=true;
    sum++;
  }
}
 cout<<(sum%2==1?sum:sum-1);
}