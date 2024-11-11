n, m = map(int, input().split())
k = 0
for i in range(n):
    storey = input()
    for j in range(0, m * 4, 4):
        if storey[j] == '1' or storey[j + 2] == '1':
            k += 1
print(k)

