#include <cstdio>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d %.5lf", a / b, a % b, (double) a / b);
}