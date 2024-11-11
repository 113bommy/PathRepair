num = int(input())
ans = [[0] * num for _ in range(num)]

for i in range(num):
    base = i // 2 * num * 2 + i % 2
    for j in range(num):
        ans[i][j] = base + j * 2

for line in ans:
    print(" ".join([str(item) for item in line]))