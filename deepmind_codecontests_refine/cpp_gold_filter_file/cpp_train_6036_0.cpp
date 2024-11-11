#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    bool f = true;
    if(s.length() < 6) f = false;
    if(any_of(begin(s), end(s), [](char c) { return isdigit(c); }) == false) f = false;
    if(any_of(begin(s), end(s), [](char c) { return isupper(c); }) == false) f = false;
    if(any_of(begin(s), end(s), [](char c) { return islower(c); }) == false) f = false;
    cout << (f ? "VALID" : "INVALID") << endl;
}