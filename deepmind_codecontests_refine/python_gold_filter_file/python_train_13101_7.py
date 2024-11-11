N,C,K = map(int, input().split())
L = []
for a in range(N):
  L.append(int(input()))
L.sort()
L.append(10**10)
x = 0
y = 0
z = L[0]
for i in range (N+1):
  if y < C and z+K >= L[i]:
    y += 1
  else:
    x += 1
    y = 1
    z = L[i]    
print(x)