N=int(input())
P=[int(i) for i in input().split()]
Q=[0]*N
for i in range(N):
    Q[P[i]-1]=i
L=30000
A=[L*(i) for i in range(1,N+1)]
B=[L*(N+1-i) + Q[i-1] for i in range(1,N+1)]
print(' '.join(map(str,A)))
print(' '.join(map(str,B)))