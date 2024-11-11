n, k = [int(_) for _ in input().split()]

a = [int(_) for _ in input().split()]

res_arr = [[] for i in range(k)]

free = [True] * (n * k + 1)

for ind, v_a in enumerate(a):
    res_arr[ind].append(v_a)
    free[v_a] = False

ind = 0
for i in range(1, n * k + 1):
    if free[i]:
        if len(res_arr[ind]) == n:
            ind += 1
        res_arr[ind].append(i)
        free[i] = False

for i in range(k):
    print(*res_arr[i], sep = " ")


