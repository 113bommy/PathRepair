#include<bits/stdc++.h>
using namespace std;
int main()
{
  int ans=1;
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
  {
    int X;
    cin>>X;
    if(X==ans)
      ans++;
  }
  ans--;
  if(ans==0)
    puts("-1");
  else	cout<<N-ans<<endl;
  return 0;
}