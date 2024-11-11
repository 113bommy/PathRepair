#include<iostream>
using namespace std;
long N,c[10][10],a;
int main(){
  cin>>N;
  for(int i=0;i<=N;i++)c[to_string(i)[0]-'0'][i%10]++;
  for(int i=0;i<10;i++)for(int j=0;j<10;j++)ans+=c[i][j]*c[j][i];
  cout<<ans<<endl;
  return 0;
}
