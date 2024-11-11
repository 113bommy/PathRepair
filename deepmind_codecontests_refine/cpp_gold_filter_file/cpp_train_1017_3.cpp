#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n , k ,s;
  cin >> n >> k >> s;
  for(int i = 1; i<=k; i++)cout << s << " ";
  for(int i = k+1; i<=n; i++) if(s<=100)cout << (s+1) << " ";
  else cout << (s-1) << " ";
  return 0;
}
