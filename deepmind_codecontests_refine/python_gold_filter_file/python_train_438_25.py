t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=set()
    flag=True
    for i in range(0,n):
        if (i+a[i])%n in s:
            flag=False
            break
        s.add((i+a[i])%n)
    if flag:
        print("YES")
    else:
        print("NO")