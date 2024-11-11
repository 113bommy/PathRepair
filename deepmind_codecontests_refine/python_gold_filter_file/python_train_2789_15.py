N = int(input())
A = list(map(int,input().split()))
s = sum(A)**2
for i in range(N):
    s -= A[i]**2
print(int(s/2))