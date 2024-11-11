n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if x>y:print(n)
else:
    c=0
    from math import ceil
    for i in a:
        if i<=x:c+=1
    print(ceil(c/2))