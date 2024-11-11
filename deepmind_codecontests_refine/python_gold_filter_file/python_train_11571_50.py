(n, v) = list(map(int, input().split()))

result = 0
if n <= v:
    result = n - 1
else:
    result = v
    for i in range(2, n+1):
        if n-i >= v:
            result += i
print(result)