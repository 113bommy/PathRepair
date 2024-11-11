n, m, k = [int(i) for i in input().split()]
lst = [int(j) for j in input().split()]
result, new_result = 1, 1
page, count = None, 0
for i in range(m):
    if (lst[i] - result) // k != page:
        count += 1
        result = new_result
        page = (lst[i] - result) // k
    new_result += 1
print(count)

