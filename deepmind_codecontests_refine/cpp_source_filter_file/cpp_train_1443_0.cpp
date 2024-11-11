#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100000;
int p=1000000007;
typedef long long ll;
int main()
{
  int n,t,i;
  int c[N_MAX];
  ll res=1;
  cin >> n;
  fill(c,c+n-1,0)
  for(i=0;i<n;i++){
    cin >> t;
    if((n+t)%2!=1||(t==0&&c[t]>=1)||c[t]>=2){
      cout << "0" << endl;
      return 0;
    }
    c[t]++;
  }
  for(i=0;i<n;i++)
    if(c[i]>0){
      res*=c[i];
      res%=p;
    }
  cout << res << endl;
  return 0;
}