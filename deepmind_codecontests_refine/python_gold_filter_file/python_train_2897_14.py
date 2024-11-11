N = int(input())
S = [input() for _ in range(N)]

Total = 0
for i in range(N):
    Synmmetry = True
    for a in range(N):
        for b in range(a, N):
            if S[a][(b + i) % N] != S[b][(a + i) % N]:
                Synmmetry = False
                break
        if not Synmmetry: break
    else: Total += 1
print(Total * N)