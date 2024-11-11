def factory(a, m):
    flag = 0
    for i in range(20):
        if a % m == 0:
            flag = 1
            break
        a += a % m
    if flag == 1:
        return "Yes"
    return "No"


A, M = [int(j) for j in input().split()]
print(factory(A, M))
