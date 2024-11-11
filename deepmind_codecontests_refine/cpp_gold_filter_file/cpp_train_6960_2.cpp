#include <bits/stdc++.h>
using namespace std;
int main()
{
  int w, h, n;
  cin >> w >> h >> n;
  int x, y, a, g, j, k, l;
  g = j = 0;
  k = w;
  l = h;
  for (int i = 0;i<n;i++){
    cin >> x >> y >> a;
    if(a==1&&g<x)
      g = x;
      else if(a==2&&k>x)
        k = x;
        else if(a==3&&j<y)
          j = y;
          else if(a==4&&l>y)
            l = y;
  }
  if(g>=k||j>=l)
    cout << 0 << endl;
    else
      cout << (k - g)*(l - j) << endl;
}
