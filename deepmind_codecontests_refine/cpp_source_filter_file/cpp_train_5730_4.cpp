#include <iostream>
#include <cstudio>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    printf("%d %d %.8lf\n", a/b, a%b, a/(double)b );
}