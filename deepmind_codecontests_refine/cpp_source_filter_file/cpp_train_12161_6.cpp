#include<iostream>
using namespace std;
#include<vector>
int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  for(int i=0;i<m;i++) cin>>b[i];

  int cnt=0;
  for(int i=0;i<n;i++){
    int res=c;
    for(Int j=0;j<m;j++){
      int a;
      cin>>a;
      res+=a*b[j];
    }
    if(res>0) cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
