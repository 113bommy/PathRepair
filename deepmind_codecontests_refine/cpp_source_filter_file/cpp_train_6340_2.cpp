#include<iostream>

using namespace std;
int euclid(int n, int m);

int main(){
  int n,m;
  while(cin>>n>>m){
    cout <<euclid(n,m<<endl;
  }
}

int euclid(int n,int m){
  if(n<m){
  int temp;
  temp=m;
  m=n;
  n=temp;
  }
  if(n%m==0){
    return m;
  }else{
    return euclid(m,n%m);
  }
}
  