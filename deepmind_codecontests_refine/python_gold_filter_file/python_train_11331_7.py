K=int(input())
N=50
A,B=divmod(K,N)
rs = []
print(N)
for i in range(N):
    rs.append(max((K//N+(i<B))*(N+1)+49-K, 0))
print(*rs)
