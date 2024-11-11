N=int(input())
inp=[]
for _ in range(N):
    inp.append(int(input()))
inp.sort()

if N%2:
    
    m1=inp[:(N//2+1)]
    M1=inp[(N//2+1):]
    
    m2=inp[:N//2]
    M2=inp[N//2:]
    
    a1=sum(M1)*2-sum(m1)*2+m1[-1]+m1[-2]
    a2=sum(M2)*2-sum(m2)*2-M2[0]-M2[1]
    
    print(max(a1,a2))
    
else:
    
    m=inp[:N//2]
    M=inp[N//2:]
    
    a=sum(M)*2-sum(m)*2+m[-1]-M[0]
    
    print(a)