n,a,b=map(int,input().split())
if (a-b)%2==0:
    print((b-a)//2)
else:
    print(min(a+(b-a-1)//2, n-b+1+(b-a-1)//2))