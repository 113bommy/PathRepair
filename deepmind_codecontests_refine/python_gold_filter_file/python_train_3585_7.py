N = int(input())
S = list(input())

x = S.count('x')
ans = abs(N // 2 - x)
print(ans)
for i in range(N):
    if S[i] == 'x' and x > N // 2:
        S[i] = 'X'
        x -= 1
    elif S[i] == 'X' and x < N // 2:
        S[i] = 'x'
        x += 1

print("".join(S))


