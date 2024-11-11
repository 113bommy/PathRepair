from collections import Counter
N = int(input())
A = list(map(int, input().split()))

x = max(A)
hurui = [x]*(x+1)
for i in range(2, x+1):
    for j in range(i, x+1, i):
        hurui[j] = min(i, hurui[j])

cnt = Counter([1])
for i in range(N):
    num = A[i]
    while num > 1:
        x = hurui[num]
        while num%x == 0:
            num //= x
        cnt[x] += 1

a = cnt.most_common(1)[0][1]
if a == 1:
    print("pairwise coprime")
elif a < N:
    print("setwise coprime")
else:
    print("not coprime")
