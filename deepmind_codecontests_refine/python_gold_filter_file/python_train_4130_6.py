n = int(input())
a = list(map(int, input().split()))
b = []

for i in range(n - 1, -1, -1):
    if a[i] not in b:
        b.append(a[i])
    else:
        pass

print(len(b))
print(*b[::-1])