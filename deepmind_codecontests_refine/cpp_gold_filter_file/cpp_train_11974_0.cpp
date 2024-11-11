#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); ++i) {
        int j = 0;
        int k = i;
        while (j < s2.size() && k < s1.size()) {
            if (s1[k] != s2[j])
                break;
            j++; k++;
        }
        if (j >= s2.size()) {
            cout << i << endl;
        }
    }

    return 0;
}