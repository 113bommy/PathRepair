# cook your dish here
for _ in range(int(input())):
    b=list(map(int,input().split()))
    first=b[0]
    last=b[-1]
    res=[first]
    for i in range(1,len(b)-1):
        for j in range(i+1,len(b)-1):
            if b[i]+b[j]==last-first:
                res.append(b[i])
                res.append(b[j])
                break
    print(*res)