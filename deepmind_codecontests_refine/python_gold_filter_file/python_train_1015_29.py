n, k = map(int, input().split())
l = []
for i in range(n):
    l.append(int(input()))

root = [1]*n

for i in range(n)[-2::-1]:
    num = 0
    for j in range(i + 1, i + 200):
        if j >= n:
            break
        if abs(l[i] - l[j]) <= k:
            num = max(num, root[j])
    root[i] += num

print(max(root))