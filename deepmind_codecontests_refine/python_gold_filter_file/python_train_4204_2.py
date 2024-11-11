x = int(input())
a = list(map(int, input().split()))
sum = 0
for i in range(x):
    ans = 0
    for j in range(i, x):
        ans ^= a[j]
        sum = max(ans, sum)
print(sum)