#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  
 int a[110]={0};
  
  for(int i=2;i<=n;i++){
    
    int sum=i;
    for(int j=2;j<=i;j++){
      
      while(sum%j==0){
        a[j]++;
        
        sum/=j;
      }
      
    }
  }
  
 int p[100]={0};
  
  for(int i=2;i<=n;i++){
    
    if(a[i]>=74){//75*1 = 74と0 = 同じ数が74 あとは同様に
      
      p[75]++;
    }
    
    if(a[i]>=24){
      p[25]++;
    }
    
    if(a[i]>=14){
      
      p[15]++;
    }
    
    if(a[i]>=4){
      p[5]++;
    }
    
    if(a[i]>=2){
      p[3]++;
    }
  }
  //全部合わせる
  //同じ素数が多いほう(25個ある方など)から先に選択すると少ないほうは必ず一つ要素が減っている。
  cout << p[75]+p[25]*(p[3]-1)+p[15]*(p[5]-1)+p[5]*(p[5]-1)/2*(p[3]-2) << endl;
  
}
