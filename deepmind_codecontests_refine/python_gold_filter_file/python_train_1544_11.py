N,X=map(int,input().split())
G=list(map(int,input().split()))

S=[0]
for g in G:
    S.append(S[-1]+g)

ANS=1<<60

def length(x):
    if x==1:
        return 5
    else:
        return 2*x+1

for rep in range(1,N+1):
    score=X*N+X*rep
    count=1
    
    for i in range(N,0,-rep):
        score+=(S[i]-S[max(0,i-rep)])*length(count)
        count+=1
        
    ANS=min(ANS,score)
    
print(ANS)