#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int ans = 0;
  for(int i =0,a;i<N;i++){cin >> a;ans+= a-1;}
  cout << ans << endl;
return 0;
}