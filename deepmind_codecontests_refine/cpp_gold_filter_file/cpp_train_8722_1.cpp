#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
    cin >> s;
    vector<string> t={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    for(int i=0;i<7;i++){
      if(s==t.at(i)){
        cout << 7-i << endl;
      }
    }
}
