#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main()
{
  int n,m;
  cin >> n >> m;
  
  for(int i=0;i<5;i++)arr[i]=-1;
  
  while(m--)
  {
    int i,x;
    cin >> i >> x;
    if(arr[i]!=x and arr[i]!=-1)
    {
      cout << -1;
      return 0;
    }
    arr[i]=x;
  }
  
  if(arr[1]==-1 and n>1)arr[1]=1;
  else if(arr[1]==-1 and n==1)arr[1]=0;
  for(int i=2;i<=n;i++)if(arr[i]==-1)arr[i]=0;
  
  if(n>1 and arr[1]==0)
  {
    cout << -1;
    return 0;
  }
  
  for(int i=1;i<=n;i++)cout << arr[i];
  
}
