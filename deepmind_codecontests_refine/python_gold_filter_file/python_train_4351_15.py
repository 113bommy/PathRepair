A=[]
for i in [0]*3:
    A+=list(map(int,input().split()))
N=int(input())
B=[0]*9
for i in range(N):
    i=int(input())
    if i in A:
        B[A.index(i)]=1
res=0
for i in range(3):
    res+=B[3*i]*B[3*i+1]*B[3*i+2]
    res+=B[i]*B[i+3]*B[i+6]
res+=B[0]*B[4]*B[8]+B[2]*B[4]*B[6]
print(['No','Yes'][res>0])