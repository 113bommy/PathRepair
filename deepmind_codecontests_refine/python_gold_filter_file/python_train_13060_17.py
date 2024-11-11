n = int(input())

if n % 2 == 0:
    s = [6, n-6]
else:
    s = [9, n-9]

for x in s:
    print(x, end=' ')