I,i,H=input,int,range
n,L,R,A,C=i(I()),[0],[0],0,0
for _ in H(n):l,r=map(i,I().split());L+=[l];R+=[r]
L=sorted(L)[::-1];R.sort()
for j in H(n):C+=(L[j]-R[j])*2;A=max(A,C)
print(A)