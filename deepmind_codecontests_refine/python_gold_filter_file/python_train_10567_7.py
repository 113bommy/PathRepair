s = list(input())
n = int(input())

for _ in range(n):
    l, r, k = map(int, input().split())
    l -= 1
    r -= 1
    if r - l > 0:
        k %= r - l + 1
        s[l:r+1] = s[r-k+1:r+1] + s[l:r-k+1]

print("".join(s))
