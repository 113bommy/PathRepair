#include <iostream>
#include <string>
#include <algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    int n , max , min , sa;
    string s;
    cin >> n;
    while(n--){
        cin >> s:
        sort(s.begin() , s.end());
        min=atoi(s.c_str());
        reverse(s.begin() , s.end());
        max=atoi(s.c_str());
        sa=max-min;
        cout << sa << endl;
    }
	return 0;
}