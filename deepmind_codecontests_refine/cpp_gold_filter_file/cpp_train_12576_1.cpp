#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z,n,a;
  	cin>>n;
  	x=y=z=a=0;
  	for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int m = s.length();
      if (s[0]=='B' && s[m-1]=='A')
        z++;
      else if (s[0]=='B')
        x++;
      else if (s[m-1]=='A')
        y++;
      for (int j = 1; j < m; j++)
        if (s[j-1]=='A'&&s[j]=='B')
          a++;
    }
  	if (z) {
    	a += z-1;
      	if (x) x--,a++;
      	if (y) y--,a++;
    }
  	cout << a + min(x,y) << endl;
}