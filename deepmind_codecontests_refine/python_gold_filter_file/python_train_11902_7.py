# cook your dish here
t=int(input())
for i in range(0,t):
    n,x,k=list(map(int,input().split()))
    if k<x:
        print(0)
    else:
        n1=k//x
        n1=min(n,n1)
        s=(n1*(n1-1))//2
        s+=((n-n1)*(k//x))
        print(s)
        