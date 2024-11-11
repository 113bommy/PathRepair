#include<iostream>
int main(){
  int n,A[100];
  std::cin>>n;
  for(int i=0;i<n;i++){
    std::cin>>A[i];
  }
  for(int i=0;i<n;i++){
    if(i!=0){
      for(int j=0;j<i;j++){
	if(A[i-j]<A[i-j-1]){
	  int ex=A[i-j];
	  A[i-j]=A[i-j-1];
	  A[i-j-1]=ex;
	}//入れ替え
      }
    }
    for(int k=0;k<n;k++){
      std::cout<<A[k];//出力
      if(k<n-1)std::cout<<' ';
    }
    std::cout<<'\n';
  }
  return 0;
}
