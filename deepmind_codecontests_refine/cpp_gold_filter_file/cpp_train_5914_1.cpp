#include <iostream>
using namespace std;
int main()
{
  int n,ans=0;
  int p[21];
  cin>>n;
  for(int i=1;i<=n;i++) cin>>p[i];
  for(int i=2;i<n;i++) if(p[i-1]<p[i]&&p[i]<p[i+1]||p[i-1]>p[i]&&p[i]>p[i+1]) ans++;
  cout<<ans;
}