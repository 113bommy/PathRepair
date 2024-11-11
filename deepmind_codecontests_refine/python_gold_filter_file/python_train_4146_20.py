from collections import Counter

def get_smallest_power_of_2_over_N(N):
    i=2
    while i<=N:
        i*=2
    return i

N = int(input())
A = list(map(int,input().split()))


A = sorted(A)

ans=0
D=Counter(A)

for i in reversed(range(N)):
    pair_val = get_smallest_power_of_2_over_N(A[i]) - A[i]
    if D[A[i]]<=0:
        continue
    elif pair_val==A[i] and D[pair_val]>=2 or pair_val!=A[i] and  D[pair_val]>=1:
        ans+=1
        D[pair_val]-=1
        D[A[i]]-=1

print(ans)
