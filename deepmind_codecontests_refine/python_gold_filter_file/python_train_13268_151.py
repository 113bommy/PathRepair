n = int(input() )
sum = 0
for i in range(n):
    a = list(map(int,input().split()))
    p = a[0]
    q = a[1]
    if q - p >= 2:
        sum += 1
print(sum)