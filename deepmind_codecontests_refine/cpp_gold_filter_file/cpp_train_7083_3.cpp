#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,s1,s2;

  while(1){
  cin >> s;
  if(s == "-")return 0;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
    {
      int a;
      cin >> a;

      s1 = s.substr(0,a);
      s2 = s.substr(a ,s.size());
      s = s2 + s1;
 
    }
  cout << s << endl;
  }
  return 0;
}
