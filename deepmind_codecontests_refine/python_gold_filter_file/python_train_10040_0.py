#!/usr/bin/python3
from sys import exit
n,t = input().split()
n = int(n)
t = int(t)
test_case = input()
a = []
#matrix = [ 0 for x in range(101)]
for w in test_case.split():
    r = int(w)
    a.append(r)
#a.sort()
ans = 0
k = 0
for i in range (n):
    if( (k + a[i]) > t):
        ans += 1
        k = a[i]
    else:
        k += a[i]
print(ans+1)
exit()

