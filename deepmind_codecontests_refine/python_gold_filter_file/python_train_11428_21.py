N,X,M=map(int,input().split())

seen=[-2]*M
seen[X]
A=[X]
i=1
while(i<N):
    T=A[-1]**2%M
    if seen[T]!=-2:
        Roop=i-seen[T]
        Left,Right=seen[T],i
        break
    A.append(T)
    seen[T]=i
    i+=1

if i==N:
    print(sum(A))
    exit()

Roopsum=0
for i in range(Left,Right):
    Roopsum+=A[i]

Rest=N-len(A)

ans=sum(A)

ans+=Rest//Roop*Roopsum

for i in range(Rest%Roop):
    ans+=T
    T=T**2%M
print(ans)