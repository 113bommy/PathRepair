n,m=map(int,input().split())
if n==1 or m==1:
    print(1)
else:
    print(-((-n*m)//2))