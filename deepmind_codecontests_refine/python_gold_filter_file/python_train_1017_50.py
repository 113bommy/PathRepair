n, k, s = map(int, input().split())

a = [s] * k
a += [9857349] * (n - k)

print(*a, sep=' ')
