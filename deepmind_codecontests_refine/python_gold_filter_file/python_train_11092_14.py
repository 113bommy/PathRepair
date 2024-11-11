I=input
R=range
S=sorted
n=int(I())
r=[[],[]]
for s,v in zip(I(),map(int,I().split())):r[s=='R']+=[v]
m=10**9
i=0
j=0
a=S(r[0])
b=S(r[1])
while i<len(a) and j<len(b):
    if b[j]>a[i]:i+=1
    else:m=min(m,(a[i]-b[j])//2);j+=1
print([m,-1][m==10**9])