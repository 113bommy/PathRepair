
t = int(input())
v = list(map(int, input().split()))
a = []
index = 1

for j in v:
    a.append((j,index))
    index += 1

a = sorted(a, reverse=True)
total = 0
ans = []

for i in range(t):
    
    total += a[i][0]*i + 1
    ans.append(a[i][1])
    
print(total)
print(*ans)