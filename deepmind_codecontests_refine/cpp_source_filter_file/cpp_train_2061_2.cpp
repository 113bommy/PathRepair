#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0 ; i < n ; i++){
        if (((i % 2 == 0)&&(s[i] == 'L'))||((i % 2 == 1)&&(s[i] == 'R'))){cout << "No" <<endl ; return 0;}
    }

    cout << "Yes" <<endl;
    return 0;
}
