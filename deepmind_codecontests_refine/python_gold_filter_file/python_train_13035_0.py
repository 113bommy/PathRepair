import math
n=int(input())
for i in range(n):
    e=10**10
    f=10**10
    a,b,c=[int(i) for i in input().split()]
    d=[int(i) for i in  input().split()]
    for i in range(b,(a+1)):
        if(i not in d):
            e=i
            break
    for i in  range(b,0,-1):
        if(i not in d):
            f=i
            break
    if(e<10**10 or f<10**10):
        print(min(abs(b-e),abs(b-f)))
    else:
        print(0)