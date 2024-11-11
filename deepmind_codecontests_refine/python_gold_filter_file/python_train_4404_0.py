from math import gcd
def row(a,b):
    if len(a)==1:
        for i in b:
            print(a[0]+i,end=" ")
        return ""
    base=list(map(lambda s:s-a[0],a[1:]))
    curr=gcd(base[0],base[1])
    for i in base[2:]:
        curr=gcd(curr,i)
    for i in b:
       print(gcd(i+a[0],curr),end=" ")
    return ""

a=input()
ls1=list(map(int,input().strip().split()))
ls2=list(map(int,input().strip().split()))
print(row(ls1,ls2))