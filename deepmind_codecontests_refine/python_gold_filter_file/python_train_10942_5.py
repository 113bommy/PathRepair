# import os

t = int(input())

for _ in range(t):
    s,a,b,c = map(int,input().split())

    r = s//c
    free = (r//a)*b
    print(r+free)

