#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<n;i++)


int main()
{
   int n,m;
  cin>>n>>m;
  
  vector<int>s(m);
  string c[m];
  
  rep(i,m)
  {
     cin>>s[i]>>c[i];
  }

for(int x=0;x<1000;x++)
{
   string a = to_string(x);
   if(a.size()!=n) continue;
  
   bool ok = true;
   for(int i=0;i<m;i++)
   {
       if(a[s.at(i)-1] != c[i]) ok = false;
 
   }
  if(ok)
  {  
    cout<<x<<endl;
    return 0;
  }
}

cout<<-1<<endl;
  
  return 0;

}
