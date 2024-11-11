#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n;
set<int>S;
main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int c,x;cin>>c>>x;
    if(c==1)cout<<(S.find(x)!=S.end())<<endl;
    else if(c==0)S.insert(x),cout<<S.size()<<endl;
    else if(c==2)S.erase(x);
    else
    {
      int y;cin>>y;
      auto a=S.lower_bound(x),b=S.upper_bound(y),u=0;
      for(auto it=a;it!=b;it++)cout<<*it<<endl;
    }
  }
}

