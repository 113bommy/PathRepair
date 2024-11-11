#7/4/19
#390A
#BlueyNeilo

n=int(input())
V, H = [False]*101, [False]*101

for _ in range(n):
    x, y = list(map(int,input().split()))
    V[x] = True
    H[y] = True
    
print(min(V.count(True), H.count(True)))
