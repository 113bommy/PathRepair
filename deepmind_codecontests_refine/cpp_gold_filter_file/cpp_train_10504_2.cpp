#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int L, A, B, C, D;

    cin >> L >> A >> B >> C >> D;
    cout << L - max(ceil((double)A / C), ceil((double)B / D)) << endl;

    return 0;
}