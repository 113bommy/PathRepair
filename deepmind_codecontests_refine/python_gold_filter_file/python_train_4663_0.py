N = int(input())
ans = set()

def check(N, k):
    if k<2:
        return False
    N //= k
    while N:
        if (N-1)%k==0:
            return True
        if N%k:
            return False
        N //= k

for k in range(1, int(N**0.5)+1):
    if (N-1)%k==0:
        ans.add(k)
        ans.add((N-1)//k)
    if N%k==0:
        if check(N, k):
            ans.add(k)
        if check(N, N//k):
            ans.add(N//k)

ans.remove(1)
print(len(ans))