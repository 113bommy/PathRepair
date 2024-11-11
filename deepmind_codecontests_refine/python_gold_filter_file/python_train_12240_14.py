n, m, k = map(int,input().split())
m = 2*m
ans = 'R'
if k & 1:
    ans = 'L'
    k += 1
ans1 = k / m
if ans1 != int(ans1):
    ans1 = int(ans1) + 1
ans2 = (k - m * (int(ans1) - 1)) // 2
print(int(ans1),ans2, ans)
