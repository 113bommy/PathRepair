n=int(input())
p=[list(map(int,input().split()))for i in range(n-1)]
for i in range(n):
    c=0
    d=p[i:]
    for j in range(n-i-1):
        if c<d[j][1]:
            c+=d[j][1]+d[j][0]-c
        else:
            c+=((c-1)//d[j][2]+1)*d[j][2]+d[j][0]-c
    else:
        print(c)