n,a,b=map(int,input().split())

if (b-a)%2==0:
    print(abs((b-a)//2))
else:
    print(min((a+b-1)//2,(2*n-a-b+1)//2))