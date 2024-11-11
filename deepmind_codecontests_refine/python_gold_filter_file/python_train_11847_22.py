n,a,b=map(int,input().split())
if (b-a-1)%2==1:
    print((b-a-1)//2+1)
else:
    print(min(a-1,n-b)+1+(b-a-2)//2+1)