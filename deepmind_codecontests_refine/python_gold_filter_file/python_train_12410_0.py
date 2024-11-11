t=int(input())
while t>0:
    n,k1,k2=map(int,input().split())
    a1=list(map(int,input().split()))
    a2=list(map(int,input().split()))
    #print(a1,a2)
    m1=max(a1)
    m2=max(a2)
    if m1>m2:
        print("YES")
    else:
        print("NO")
    t-=1
