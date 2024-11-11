#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pint;

int main(){
  int n;
  cin>>n;
  vector<pint> a(n),b(n);
  for(int i=0;i<n;++i)cin>>a[i].first>>a[i].second;
  for(int i=0;i<n;++i)cin>>b[i].first>>b[i].second;
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ans=0;
  multiset<int> st;
  int j=0;
  for(int i=0;i<n;++i){
    while(a[j].first<b[i].first&&j<n)st.insert(a[j++].second);
    auto it=st.lower_bound(b[i].second);
    if(it!=st.begin()){
      ans++;
      st.erase(--it);
    }
  }
  cout<<ans<<endl;
}
