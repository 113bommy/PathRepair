t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    d = {}
    for i in range(n):
        tmp = (i+arr[i])%n
        if tmp not in d.keys():
            d[tmp]=1
        else:
            d[tmp]+=1
    ck = True
    for (i,j) in d.items():
        if(j>1):
            ck=False
            break
    if ck:
        print("YES")
    else:
        print("NO")