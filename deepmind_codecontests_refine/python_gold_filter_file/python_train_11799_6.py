n, t = [int(item) for item in input().split()]
cont = []

for i in range(n):
    center, length = [int(item) for item in input().split()]
    cont.append([center - length / 2, center + length / 2])

cont.sort(key=lambda item: item[0])
# cont=sorted(key=lambda item: item[0])
ans = 2
for i in range(n - 1):
    gap = cont[i + 1][0] - cont[i][1]
    if gap > t:
        ans += 2
    elif gap == t:
        ans += 1

print(ans)
