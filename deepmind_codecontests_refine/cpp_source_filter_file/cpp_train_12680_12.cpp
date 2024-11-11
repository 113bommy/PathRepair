#include<bits/stcd++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main() {
	string s; cin >> s;
  	int c = 0;
  	rep(i, s.size()) if (s[i]=='x') c++;
  	cout << (c < 8 ? "YES" : "NO") << endl;
}