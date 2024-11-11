n,k = [int(i) for i in input().split(" ")]
for i in range(0,k):
    if n % 10 == 0:
        n = n // 10
    else:
        n -= 1
print(n)