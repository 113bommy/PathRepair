from math import pow
t=int(input())
while t:
    n=int(input())
    l = list(map(int,input().split()))
    l.sort()
    min=l[1]-l[0]
    for i in range(1,n):
        diff=l[i]-l[i-1]
        if min>diff:
            min=diff
    print(min)
    t -= 1