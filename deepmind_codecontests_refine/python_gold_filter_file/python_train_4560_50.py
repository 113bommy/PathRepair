n,k = map(int,input().split())
A = sorted(list(map(int,input().split())))
F = sorted(list(map(int,input().split())),reverse=True)

low = -1
high = 10**12

while high - low > 1:
    score = (low+high)//2
    training = 0
    for i in range(n):
        if A[i]*F[i] > score:
            training += A[i] - score//F[i]
    if training <= k:
        high = score
    else:
        low = score
        
print(high)