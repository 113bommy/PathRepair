nclude<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){
  int i,j,cnt=0;
  int n,m;
  cin>>n;
  int d[n];
  for(i=0;i<n;i++)cin>>d[i];
  cin>>m;
  int t[m];
  for(i=0;i<m;i++)cin>>t[i];
  sort(d,d+n);
  sort(t,t+m);
  for(i=0;i<n;i++){
    if(d[i]==t[cnt])cnt++;
  }
  if(cnt==m)cout<<"YES";
  else cout<<"NO";
}