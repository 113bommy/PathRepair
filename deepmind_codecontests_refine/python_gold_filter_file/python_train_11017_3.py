N = int(input())
a = list(map(int,input().split()))

m = 0
manu = []

for i in range(1,N):
    if abs(a[m]) < abs(a[i]):
        m = i

for i in range(N):
    if a[m]*a[i] < 0:
        a[i] += a[m]
        manu.append([m,i])

if a[m] >= 0:
    for i in range(N-1):
        if a[i] > a[i+1]:
            a[i+1] += a[i]
            manu.append([i,i+1])

else:
    for i in range(N-1):
        if a[N-i-2] > a[N-i-1]:
            a[N-i-2] += a[N-i-1]
            manu.append([N-i-1,N-i-2])
    
print(len(manu))
for i in range(len(manu)):
    manu[i][0] += 1
    manu[i][1] += 1
    print(" ".join(list(map(str,manu[i]))))