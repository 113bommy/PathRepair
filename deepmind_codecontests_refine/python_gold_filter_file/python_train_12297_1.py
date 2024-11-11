a=int(input())
for i in range(a):
    l,r=map(int,input().split())
    k=0
    if(l==r):
        if(l%2==0):
            print(l)
        else:
            print(-l)
    else:
        if(l%2==0):
            k=-1
        else:
            k=1
        if(((r-l+1)%2)==0):
            print(k*(r-l+1)//2)
        else:
            print(k*(r-l)//2-k*r)