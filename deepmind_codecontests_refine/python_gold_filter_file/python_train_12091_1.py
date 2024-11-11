def emotions(lst, m, k):
    return m // (k + 1) * (lst[-1] * k + lst[-2]) + (m % (k + 1)) * lst[-1]


n, M, K = [int(i) for i in input().split()]
a = [int(j) for j in input().split()]
print(emotions(sorted(a), M, K))