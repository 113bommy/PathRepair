


n, k = [int(i) for i in input().split()]
p = list(range(1, n - k)) + list(range(max(n - k, 1), n + 1))[::-1]
print (' '.join([str(i) for i in p]))