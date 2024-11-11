n = int(input())
a = list(map(int, input().split()))
equator = sum(a)/2
sub = 0
for i in range(n):
    sub += a[i]
    if (sub >= equator):
        print(i + 1)
        break
