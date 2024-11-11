n,m=map(int,input().split())
x=[int(q) for q in input().split()]

x=sorted(x)
a=1
for i in range(n-1):
    if x[i]==x[i+1]:
        a+=1
    elif x[i]<x[i+1]<=x[i]+m:
        n-=a
        a=1
    else:
        a=1
print(n)