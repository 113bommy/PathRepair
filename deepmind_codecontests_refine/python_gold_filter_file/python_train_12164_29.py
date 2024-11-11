N = int(input())
t = list(map(int,input().split()))
v = list(map(int,input().split()))
T = sum(t)*2
vt = [min(i/2,(T-i)/2) for i in range(T+1)]
ts = 0
te = 0
for i in range(N):
    te += t[i]*2
    for j in range(T+1):
        vt[j] = min(vt[j],v[i]+max(0,-(j-ts)/2,(j-te)/2))
    ts = te
print(sum(vt)/2)