M= 10**9+7
ans = 1

N=int(input())
S=list(input())
S_set = set(S)

for i in S_set:
    ans *= (S.count(i)+1)

print((ans-1) % M)