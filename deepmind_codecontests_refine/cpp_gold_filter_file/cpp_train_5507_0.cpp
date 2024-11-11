#include<iostream>
#include<cstdio>
#include<cstring>
#define SWAP(type,a,b) do{type temp=a;a=b;b=temp;}while(0)
using namespace std;
int main(){
  int n[501],m[501][501],tmp[501];
  int nt,mt,a,b,sum=0;
  while(1){
    sum=0;
    for(int i=0;i<=500;i++){
      for(int j=0;j<=500;j++){
	m[i][j]=0;
      }
      n[i]=tmp[i]=0;
    }
      
    cin >> nt >> mt;
    if(nt==0&&mt==0)break;
    for(int i=0;i<mt;i++){
      cin >> a >> b;
      if(b<a)SWAP(int,a,b);

      if(a==1){
	n[b]=tmp[b]=1;
      }else{
	m[a][b]=1;
	m[b][a]=1;
      }
    }
    for(int i=2;i<=500;i++){
      if(n[i]==1){
	for(int j=2;j<=500;j++){
	  if(m[i][j]==1)tmp[j]=1;
	}
      }
    }
    for(int i=2;i<=500;i++){
      if(tmp[i]==1){
	sum++;
      }
    }
    cout << sum << endl;
  }
}