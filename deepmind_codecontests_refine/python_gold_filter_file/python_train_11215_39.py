n=int(input())
a=list(map(int,input().split()))
if n==1 or (n==2 and a[0]==a[1]):
    print(-1)
else:
    print(1)
    print(a.index(min(a))+1)