#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll cnt=0;
  ll ans=0;
  string s;
  cin>>s;
  for(ll i=0;i<s.size();i++){
  	if(s[i]!='A'&&s[i]!='C'&&s[i]!='G'&&s[i]!='T'){ans=max(ans,cnt);cnt=0;}
    else cnt++;
  }
  ans=max(ans,cnt);
  cout<<ans<<endl;
}
