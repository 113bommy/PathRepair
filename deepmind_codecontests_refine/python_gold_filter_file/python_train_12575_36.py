N = int(input())
S = input()

ans = 0
left, right = 0, 1
while right < N:
    s = S[left:right]
    if s in S[right:]:
        ans = max(ans, len(s))
        right += 1
    else:
        left += 1

print(ans)
