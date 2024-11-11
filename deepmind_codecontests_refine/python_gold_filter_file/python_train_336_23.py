from sys import stdin
ip = stdin.readline
n = int(ip())
m = int(1e9)+7
f=1
a=1
for i in range(2, n+1):
    f=(f*i)%m
    a=(a*2)%m
print((f-a+m)%m)