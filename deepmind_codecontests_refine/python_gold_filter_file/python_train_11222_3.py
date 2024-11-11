N = int(input())
h =list(map(int,input().split()))
L = [0] * N

for i in range(N-2,-1,-1):
  if h[i] >= h[i+1]:
    L[i] = L[i+1] + 1
    
print(max(L))