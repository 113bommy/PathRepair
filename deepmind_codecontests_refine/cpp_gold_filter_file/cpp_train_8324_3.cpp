#include<stdio.h>
#include<math.h>
#include<algorithm>
int main(){double d;scanf("%lf",&d);printf("%.11f\n",d>=1?d=std::max(1.0+(int)d,sqrt(2)*d):sqrt(2)*d);}