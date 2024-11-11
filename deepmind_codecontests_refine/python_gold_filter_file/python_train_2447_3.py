n = int(input())
L = list(map(int, input().split()))
r = 0
d = 0
for k in range(n):
    if L[k] == 1:
        r+=1
        d=1
    elif k<n-1:
        if L[k+1] == 1 and d == 1:
            r+=1
        else:
            d = 0
print(r)
