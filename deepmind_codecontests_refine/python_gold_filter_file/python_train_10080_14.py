s=input()
K=int(input())

N=len(s)
S=set()
for i in range(N):
    for j in range(i+1,min(i+6,N+1)):
        S.add(s[i:j])
l=sorted(list(S))
print(l[K-1])