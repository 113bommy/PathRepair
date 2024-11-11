minpr = 101
n, m = map(int, input().split())
for i in range(n):
    a, b = map(int, input().split())
    prpkg = a / b
    if prpkg < minpr:
        minpr = prpkg
print(minpr * m)