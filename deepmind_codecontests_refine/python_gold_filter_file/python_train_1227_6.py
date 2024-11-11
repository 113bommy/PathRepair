import math
pi = math.acos(-1)
N, L = map(int, input().split())
NN = N * (N-1) * (N-2) // 6
T = [int(input()) for _ in range(N)]
print(sum([sum([math.cos((T[i]+T[j])*pi/L) * (N+2*(i-j)) for j in range(i+1, N)]) for i in range(N)])/NN, sum([sum([math.sin((T[i]+T[j])*pi/L) * (N+2*(i-j)) for j in range(i+1, N)]) for i in range(N)])/NN)