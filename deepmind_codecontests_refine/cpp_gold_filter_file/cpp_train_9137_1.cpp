#include <bits/stdc++.h>
#define per(i,a,n) for(int i=a;i<=n;i++)
#define ls l+mid>>1
#define rs mid+1+r>>1
using namespace std;
typedef  long long ll;
int vp[10010];
char s[200010];
int main()
{
  int n,p;
  cin>>n>>p;
  ll ans=0;
  scanf("%s",s+1);
  ll kk=1,an=0;
  vp[0]=1;
  if(p==2||p==5){
    for(int i=n;i>=1;i--){
        if((s[i]-'0')%p==0)
            ans+=i;
    }
    cout<<ans<<endl;
  }
  else{
    for(int i=n;i>=1;i--){
         an=an+((s[i]-'0')*kk)%p;
         an%=p;
         ans+=vp[an];
         vp[an]++;
         kk=kk*10%p;
    }
    cout<<ans<<endl;
  }
  return 0;
}

