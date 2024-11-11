# https://codeforces.com/contest/1594/problem/B

n = int(input())
for _ in range(n):
    base, k = map(int, input().split())
    answer = 0
    for i in range(30):
        shifted_k = k >> i
        if shifted_k == 0: break
        answer += (shifted_k % 2) * base ** i
    answer %= 10**9+7
    print(answer)
