n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(n):
    a[i] -= b[i]
a.sort()
ans = 0
i = 0
j = n - 1
while i  <j:
    if a[i] + a[j] > 0:
        ans += j - i
        j -= 1
    else:
        i += 1
print(ans)
