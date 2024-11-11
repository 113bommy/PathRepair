q=int(input())
for _ in range(q):
    a,b,n,s=map(int,input().split())
    if s-n*a>b:
        print("NO")
    elif s-n*(s//n)>b:
        print("NO")
    else:
        print("YES")