N, K = map(int,input().split())
li_ = []
for i in range(K):
    d = int(input())
    li_ += list(map(int,input().split()))
print(N -len(set(li_)))
