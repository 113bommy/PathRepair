N = int(input())
bo = 10
ans = 0
if N%2 == 0:
    while bo <= N:
        ans += N // bo
        bo *= 5
print(ans)