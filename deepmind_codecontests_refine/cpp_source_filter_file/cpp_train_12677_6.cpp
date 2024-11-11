#include<iosteram>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  int a[n],b[m];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  long long t=0;
  for(int i=0;i<m;i++) t+=b[i];
  int j=m;
  int ans=0;
  for(int i=0;i<n+1;i++){
    while(j>0&&t<k){
      --j;
      t-=b[j];
    }
    if(t>k) break;
    ans=max(ans,i+j);
    if(i==n) break;
    t+=a[i];
  }
  cout<<ans<<endl;
  return 0;
}