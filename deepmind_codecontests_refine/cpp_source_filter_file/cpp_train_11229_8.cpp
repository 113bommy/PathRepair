#Include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
cin >> s;
cout << s.substr(0, 4) << ' ' << s.substr(4, 8) << "\n";
return 0;
}