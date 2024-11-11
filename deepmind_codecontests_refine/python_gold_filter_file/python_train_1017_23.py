N,K,S = map(int,input().split())
t = [999999999]*N
for i in range(K):
    t[i] = S
print(*t)