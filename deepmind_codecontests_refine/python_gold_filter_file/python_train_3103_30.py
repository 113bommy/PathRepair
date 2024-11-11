n = int(input())
w = list(map(int,input().split()))

m=[]
for i in range(1,n):
    m.append(abs(sum(w[:i]) - sum(w[i:])))
print(min(m))