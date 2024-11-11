#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, cnt = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "A") { cnt++; }
        else {
            cnt--;
            if (cnt < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << (cnt == 0 ? "YES" : "NO") << endl;
    
    return 0;
}
