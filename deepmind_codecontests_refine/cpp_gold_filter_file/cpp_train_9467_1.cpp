#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,s,k;
  while(cin>>a>>b,a){
    int m=1e9;
    for(int i=1;i*i<=a;i++){
      if(a%i)continue;
      for(int j=1;j*j<=b;j++){
        if(b%j)continue;
        int p[4];
        p[0]=i;p[1]=a/i;p[2]=j;p[3]=b/j;
        sort(p,p+4);
        for(s=k=0;k<3;k++)s+=(p[k+1]-p[k])*(p[k+1]-p[k]);
        m= min(m,s);
    }
  }
  cout<<m<<endl;
}
}