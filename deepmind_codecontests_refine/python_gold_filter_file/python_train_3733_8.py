n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=[list(map(int,input().split())) for _ in range(m)]
for i in b:
    print(sum(a)-a[i[0]-1]+i[1])
