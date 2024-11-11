import sys
n=int(input())
L=[int(i) for i in input().split()]
for i in range(n-1):
    if L[i]<L[i+1]:
        a,b=L[i],L[i+1]
    else:
        a,b=L[i+1],L[i]
    for j in range(i+2,n-1):
        c,d=min(L[j],L[j+1]),max(L[j],L[j+1])
        if (a<c and c<b and b<d) or (c<a and a<d and d<b):
            print("yes")
            sys.exit(0)
print("no")
sys.exit(0)