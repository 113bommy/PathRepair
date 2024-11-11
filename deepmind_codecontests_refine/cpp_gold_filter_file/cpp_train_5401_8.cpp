#include<bits/stdc++.h>
using namespace std;
bool sosu(int q);
int mem[10005]={0};
int main(){
  int n;
  while(1){
    cin>>n;
    if(n==0) break;
    int q;
    for(q=n-((n+1)%2);q-2>1;q-=2){
      if(sosu(q)&&sosu(q-2)){
	cout<<q-2<<" "<<q<<endl;
	break;
      }
    }
  }
}
bool sosu(int q){
  if(mem[q]==1){
    return 1;
  }
  else if(mem[q]==-1){
    return 0;
  }
  else{
    for(int i=3;i<=sqrt(q);i+=2){
      if(mem[i]==0||mem[i]==1){
	for(int j=i;j<=q;j+=i){
	  mem[j]=0;
	  if(j==q){
	    return 0;
	  }
	}
      }
    }
    if(mem[q]==0){
      mem[q]=1;
      return 1;
    }
  }
}