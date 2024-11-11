N = int(input())
S = input()
ans = S.count("R") * S.count("G") * S.count("B")
for i in range(N):
    for j in range(i + 1, N):
        k = j - i + j
        if k < N:
            if {S[i], S[j], S[k]} == {"R", "G", "B"}:
                ans -= 1
print(ans)