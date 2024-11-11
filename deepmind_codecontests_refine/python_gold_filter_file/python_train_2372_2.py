N=int(input())
S=input()

ans = S.count("R")*S.count("G")*S.count("B")

tmp=0

for i in range(N):
  for j in range(i,N):
    if j-i+j < N:
      if S[i]!=S[j] and S[j]!=S[j-i+j] and S[i]!=S[j-i+j]:
        tmp += 1

ans = ans - tmp
print(ans)