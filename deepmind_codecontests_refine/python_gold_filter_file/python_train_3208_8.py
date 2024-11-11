n = int(input())
ans = []

if n % 2 == 0:
    temp = n + 1
else:
    temp = n

for i in range(1, n):
    for j in range(i+1, n+1):
        if i + j != temp:
            ans.append((i, j))

print(len(ans))
for a in ans:
    print(a[0], a[1])