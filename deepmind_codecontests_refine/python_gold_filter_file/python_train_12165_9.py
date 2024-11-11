N,K=map(int,input().split())
li=sorted([list(map(int,input().split())) for _ in range(N)])
for l in li:
    K-=l[1]
    if K<=0:
        print(l[0])
        break