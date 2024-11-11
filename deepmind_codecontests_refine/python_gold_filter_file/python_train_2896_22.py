N,K = map(int,input().split())
a = list(map(int,input().split()))

for i in range(N-1):
    a[i+1] += a[i]
a = [0]+a
s = []
for i in range(1,N+1):
    for j in range(i):
        s.append(a[i]-a[j])

ans = 0
for n in range(39,-1,-1):
    n2 = 2**n
    s_ = [s[i]%n2 for i in range(len(s)) if s[i]&n2 == n2]
    if len(s_) >= K:
        ans += n2
        s = s_

print(ans)