#include <cstdio>
using namespace std;

int main(){
    long double A, B;
    scanf("%Lf\n%Lf", &A, &B);
    if (A > B) printf("GREATER\n");
    else if (A < B) printf("LESS\n");
    else if (A == B) printf("EQUAL\n");
    return 0;
}