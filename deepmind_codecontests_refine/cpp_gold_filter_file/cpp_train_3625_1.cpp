#include <bits/stdc++.h>
using namespace std;
static auto re = regex("^A[a-z]+C[a-z]+$");
int main(void) {
    string s;
    cin >> s;
    if (regex_search(s, re)) {
        cout << "AC\n";
    } else {
        cout << "WA\n";
    }
    return 0;
}
