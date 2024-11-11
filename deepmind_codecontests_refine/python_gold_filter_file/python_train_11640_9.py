n = int(input())
h = list(map(int, input().split()))

for i in range(n-1):
  a = h[i+1] - h[i] 
  if a < 0:
    print('No')
    exit()
  if a >= 1:
    h[i+1] -= 1
print('Yes')