s=list(input())

K=int(input())

L=[]

for i in range (1,K+1):
    for j in range (0, len(s)-i+1):
        L.append("".join(s[j:j+i]))

L=sorted(set(L))

print(L[K-1])

