a,b,c,d=map(int,input().split())
s=0

s1=0
cnt=min(a,c,d)
s1 += 256*cnt
a-=cnt
c-=cnt
d-=cnt
if (a>0):
    s1+= 32*min(a,b)
print(s1)
