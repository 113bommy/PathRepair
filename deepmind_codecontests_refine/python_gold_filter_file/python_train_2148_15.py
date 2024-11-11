n=int(input())
s=list(map(int,input().split()))
eee=[0]*3*(10**5)
for i in range(n):
    eee[s[i]]=i+1

#print(eee)
minn=3*(10**5)
otvet=0
for i in range(len(eee)):
    if eee[i]!=0:
        if eee[i]<minn:
            otvet=i
            minn=eee[i]
print(otvet)
