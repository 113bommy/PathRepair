# cook your dish here
t=int(input())
while t:
    t=t-1
    #n=input()
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    s=sum(a)
    if s==m:
        print("YES")
    else:
        print("NO")
    