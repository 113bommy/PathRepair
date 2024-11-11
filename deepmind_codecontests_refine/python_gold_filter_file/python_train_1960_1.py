k,n = list(map(int,input().split()))
mod = 998244353
fact = [1]*(n+k+1)
rfact = [1]*(n+k+1)
for i in range(1, n+k):
    fact[i] = r = (i * fact[i-1]) % mod
    rfact[i] = pow(r, mod-2, mod)

save = []
for p in range(1,int((k+3)/2)):
    i = 2 * p + 1
    temp = 0
    for t in range(min(p+1,n+1)):
        if k-i+t<0:continue
        res = (fact[p] * rfact[t] * rfact[p-t]) % mod
        res *= (fact[n+k-i] * rfact[k-i+t] * rfact[n-t]) % mod
        res *= pow(2,t,mod)
        temp = (temp+res) % mod
    save.append(temp)
output = []
i = 1
while i<k:
    output.append(save[(i-1)//2])
    i+=1

for x in output+[save[-1]]+output[::-1]:
    print(x)

