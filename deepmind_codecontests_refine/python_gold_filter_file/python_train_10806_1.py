N=int(input())
V=[int(x) for x in input().split()]
C=[int(x) for x in input().split()]

Y=0
for x in range(N):
    Y+=max(0,V[x]-C[x])
print(Y)