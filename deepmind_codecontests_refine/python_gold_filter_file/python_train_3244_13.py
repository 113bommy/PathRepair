for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    a=[0,0,0,0]
    for v in arr:
        a[v%3]+=1
    c = a[0]
    add = min(a[2], a[1])
    if a[2]>a[1]:
        a[2]-=add
        c+=add+a[2]//3
    elif a[1]>a[2]:
        a[1]-=add
        c+=add + a[1]//3
    else:
        c+=a[1]
    print(c)
