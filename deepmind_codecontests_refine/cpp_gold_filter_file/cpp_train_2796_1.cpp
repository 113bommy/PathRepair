//In The Name Of GOD
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 2000000000;
const int maxn = 100000;
#define ll long long
#define pb push_back
#define mp make_pair
#define IO ios_base::sync_with_stdio(false);
int main(){
  IO;
  int n,m;
  cin>>n>>m;
  if(m==1||m==2*n-1)
    cout<<"No";
  else{
    cout<<"Yes\n";
    for(int i=0;i<2*n-1;i++)
      cout<<(i+m-n+2*n-1)%(2*n-1)+1<<endl;
  }
}
