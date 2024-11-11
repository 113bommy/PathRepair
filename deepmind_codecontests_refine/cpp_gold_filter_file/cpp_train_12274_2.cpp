#include <cstdio>

int main()
{
for(int i = 0; i < 3; ++i) {
int l[3], r[3];
for(int j = 0; j < 3; ++j)
scanf("%d", l + j);
for(int j = 0; j < 3; ++j)
scanf("%d", r + j);
int h, m, s;
s = r[2] - l[2];
if(s < 0) {s += 60; r[1] -= 1; }
m = r[1] - l[1];
if(m < 0) {m += 60; r[0] -= 1; }
h = r[0] - l[0];
printf("%d %d %d\n", h, m, s);
}
return 0;
}