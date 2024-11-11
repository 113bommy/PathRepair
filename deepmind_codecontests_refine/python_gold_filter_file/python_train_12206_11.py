I=input
n=int(I())
a=list(map(int,I().split()))
s=sum(a)
v=[]
for i in range(n):
    if a[i]==(s-a[i])/(n-1):v+=[str(i+1)]
P=print
P(len(v))
P(' '.join(v))