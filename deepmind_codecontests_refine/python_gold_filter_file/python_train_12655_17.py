I = lambda: map(int,input().split())
a,b=0,0
n,k=I()
l=list(I())
for i in range(1,n):
       if k>(l[i]+l[i-1]):
              a=k-(l[i]+l[i-1])
              l[i]+=a
              b+=a
print(b)
for i in l:print(i)
