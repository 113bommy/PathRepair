a,b,c,n=list(map(int,input().split()))
if n-(a+b-c)>=1 and c<=a and c<=b:
    print(n-(a+b-c))
else:
    print(-1)
