N,M=map(int,input().split())
L=[0]*N
R=[0]*N
right=0
pena=0
for _ in range(M):
    p,s=input().split()
    p=int(p)
    p-=1
    if R[p]==0:
        if s=='AC':
          right+=1
          R[p]=1
          pena+=L[p]
        else:
            L[p]+=1

print(right,pena)