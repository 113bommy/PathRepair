n,a,b=map(int,input().split())
if (b-a)%2==0:
    print((b-a)//2)
else:
    print(min(a+(b-a)//2,(n-b+1)+(b-a)//2))
