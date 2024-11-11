n,m=map(int,input().split())
b=[list(map(int,input().split())) for i in range(n)]
c =[int(input()) for j in range(m)]
[print(sum([d*e for d,e in zip(b[i],c)])) for i in range(n)]