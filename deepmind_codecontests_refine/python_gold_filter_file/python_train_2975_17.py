i, j = map(int, input().split())
k, l = map(int, input().split())
m, n = map(int, input().split())

c = m + k - i
a = k + i - m
e = i + m - k
f = j + n - l
b = l + j - n
d = n + l - j

print("3")
print(a, b)
print(e, f)
print(c, d)