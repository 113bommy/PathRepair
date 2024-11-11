#include <bits/stdc++.h>
using namespace std;


int main () {

    int H,W; cin >> H >> W;
    int cnt=0;

    for (int i=0; i<H; ++i) {
	string s;
	cin >> s;
	for(auto c : s) {
	    if( c == '#' ) cnt++;
	}
    }
    if( cnt == H+W-1 )
	cout << "Possible" << endl;
    else
	cout << "Impossible" << endl;
    return 0;
}
