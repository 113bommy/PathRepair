k, n, s, p = [int(i) for i in input().split()]
count = (n + s - 1) // s
result = k * count
print((result + p - 1) // p)
