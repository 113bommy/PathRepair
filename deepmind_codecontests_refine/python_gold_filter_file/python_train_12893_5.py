N=int(input())
A=[int(i) for i in input().split()]
A.sort(key=lambda x:-x)
S=[0]
for i in range(N):
  S.append(S[i]+A[i])
ans=1
for i in range(1,N):
  if A[i-1]<=2*(S[N]-S[i]):
    ans+=1
  else:
    break
print(ans)

