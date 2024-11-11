n=int(input())
a=list(map(int,input().split()))
if a==sorted(a) and len(set(a))==n:
    print(0)
else:
    print(n+1)
    print(*[1,n,5*100000])
    for i in range(n):
        print(*[2,i+1, a[i] +500000 - i])
