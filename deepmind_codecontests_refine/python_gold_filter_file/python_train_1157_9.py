n = int(input())
a = [int(i) for i in input().split()]
ans_min = 100000000
for x in range(n):
    ans = 0
    for i in range(n):
       ans += (abs(i - x) + i + x) * 2 * a[i]
    ans_min = min(ans, ans_min)
print(ans_min)