N = int(input())
S = list(input())

ans = S.count("R") * S.count("G") * S.count("B")

for i in range(N):
    for j in range(i+1,N):
        k = j-i+j
        if k<N and S[k]!=S[i] and S[k]!=S[j] and S[i]!=S[j]:
            ans -= 1

print(ans)