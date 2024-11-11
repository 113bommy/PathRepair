N, Q = [int(i) for i in input().split()]
S = input()
tdList = reversed([input().split() for _ in range(Q)])

l, r = 0, N - 1
lList, rList = [], []
for td in tdList:
    if td[0] == S[l] and td[1] == "L":
        l += 1
    elif td[0] == S[r] and td[1] == "R":
        r -= 1
    if l != 0 and S[l - 1] == td[0] and td[1] == "R":
        l -= 1
    if r != N - 1 and S[r + 1] == td[0] and td[1] == "L":
        r += 1
    if l > N - 1 or r < 0:
        break

ans = 0
if r >= l:
    ans = r - l + 1

print(ans)

