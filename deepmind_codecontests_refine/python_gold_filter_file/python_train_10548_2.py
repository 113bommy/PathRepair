n=int(input())
for i in range(n):
    p=int(input())
    l=[int(x) for x in input().split()]
    a=sorted(l)
    p=l[::2]
    p=sorted(p)
    if p==a[::2]:
        print("YES")
    else:
        print("NO")