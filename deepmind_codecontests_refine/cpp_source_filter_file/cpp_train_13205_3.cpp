#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,a,b,v[51];

int C[51][51];
void comb_table(int N){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
      if(j==0 || j==i){
        C[i][j]=1LL;
      }else{
        C[i][j]=(C[i-1][j-1]+C[i-1][j]);
      }
    }
  }
}
signed main(){
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  sort(v,v+n);
  reverse(v,v+n);
  comb_table(n);

  double temp=0;
  for(int i=0;i<a;i++){
    temp+=v[i];
  }
  cout<<fixed<<setprecision(10)<<temp/a<<endl;

  int ans=0;
  int x=0;
  if(v[a-1]==v[0]){
    for(int i=0;i<n;i++){
      if(v[i]==v[0])
      x++;
    }
    for(int i=a;i<=b;i++){
      ans+=C[x][i]
    }
    cout<<ans<<endl;
    return 0;
  }

  int a_num=0;
  for(int i=0;i<n;i++){
    if(v[a-1]==v[i])a_num++;
  }
  int a_num2=0;
  for(int i=0;i<a;i++){
    if(v[a-1]==v[i])a_num2++;
  }

  ans=C[a_num][a_num2];
  cout<<ans<<endl;


}
