#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string C;
    cin >> N >> C;
    auto b = C.begin();
    int a = count(b, b + count(b, C.end(), 'R'), 'W');
    cout << a;
}