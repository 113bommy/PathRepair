from collections import defaultdict
for _ in range(int(input())):
    n=int(input())
    l=[]
    for i in range(n):
        l.append(input())
    d=defaultdict(lambda:0)
    for i in range(n):
        for j in range(len(l[i])):
            d[l[i][j]]+=1
    values=list(d.values())
    c=1
    for i in range(len(values)):
        if values[i]%n!=0:
            c=0
            break
    if c:
        print('YES')
    else:
        print('NO')
