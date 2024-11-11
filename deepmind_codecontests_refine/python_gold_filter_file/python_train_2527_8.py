mod = 10**9 + 7
p3 = [0]*200000
p3[0] = 1
for i in range(1,len(p3)):
    p3[i] = (3*p3[i-1])%mod
def f(lAm, qAm):
    return (((lAm)*(p3[lAm-1]))%mod + ((p3[lAm])*qAm)%mod)%mod

n = int(input())
data = list(input())
aAm_ = 0
qAm_ = 0
cAm_ = 0
aAm = [0]*n
qAm = [0]*n
cAm = [0]*n
for i in range(n):
    if data[i] == "a":
        aAm_+=1
    elif data[i] == "?":
        qAm_+=1
    elif data[i] == "c":
        cAm_+=1
    aAm[i] = aAm_
    qAm[i] = qAm_
    cAm[i] = cAm_
ans = 0
for i in range(n):
    if data[i] == "b" or data[i] == "?":
        aBefore = aAm[i]
        qBefore = qAm[i] - (data[i] == "?")
        cAfter = cAm[-1] - cAm[i]
        qAfter = qAm[-1] - qAm[i]
        ans+= (f(qBefore,aBefore)*f(qAfter,cAfter))%mod
        ans%=mod
print(int(ans))