N = int(input())
S = input()
T = input()

MOD = 10 ** 9 + 7

ptn = []
i = 0
while i < N:
    if S[i] == T[i]:
        ptn.append(1)
        i += 1
    else:
        ptn.append(2)
        i += 2

if ptn[0] == 1:
    ans = 3
else:
    ans = 6

for s, t in zip(ptn[:], ptn[1:]):
    if s == 1 and t == 1:
        ans *= 2
    elif s == 1 and t == 2:
        ans *= 2
    elif s == 2 and t == 1:
        ans *= 1
    elif s == 2 and t == 2:
        ans *= 3
    ans %= MOD

print(ans)