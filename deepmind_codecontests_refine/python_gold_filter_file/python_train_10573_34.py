T=list(map(int, input().split()))
k2=T[0]
k3=T[1]
k5=T[2]
k6=T[3]
k=min(k2,k5,k6)
s=256*k
if k2>k:
    kp=min((k2-k),k3)
    s=s+32*kp
print(s)
