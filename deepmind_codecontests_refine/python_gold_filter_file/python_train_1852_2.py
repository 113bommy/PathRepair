N,X,Y = map(int, input().split())
D = [0] * N
for i in range(1,N):
  for j in range(i+1,N+1):
    D[min(abs(i-j),abs(X-i)+abs(Y-j)+1)] += 1 
print (*D[1:], sep="\n")