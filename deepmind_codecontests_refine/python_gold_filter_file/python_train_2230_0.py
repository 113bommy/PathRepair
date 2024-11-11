def cows(n, lst):
    zeros, result = 0, 0
    for i in range(n - 1, -1, -1):
        if lst[i] == 0:
            zeros += 1
        else:
            result += zeros
    return result


m = int(input())
a = [int(j) for j in input().split()]
print(cows(m, a))
