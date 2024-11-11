n = int(input())
result = [[0 for i in range(n)] for j in range(n)]
k, flag = 1, 1
for i in range(n):
    for j in range(n):
        if flag == 1:
            result[j][i] = k
        else:
            result[n - j - 1][i] = k
        k += 1
    flag = 2 if flag == 1 else 1
for i in range(n):
    print(" ".join(map(str, result[i])))



