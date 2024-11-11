N,X=map(int,input().split())
m=[int(input()) for _ in range(N)]
#print(m)

print(N+(X-sum(m))//min(m))