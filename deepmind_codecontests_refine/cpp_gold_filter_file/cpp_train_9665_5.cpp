#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  set<int>st;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    if(st.find(x)!=st.end())
    {
      st.erase(x);
    }
    else st.insert(x);
  }
  cout<<st.size()<<endl;
}
