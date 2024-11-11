a,b,c,n=map(int,input().split())
r=n-a-b+c
if r>0 and c<=a and c<=b:
    print(r)
else:
    print(-1)
