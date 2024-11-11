s=input()
c='ab'
j=0
i=len(s)
r=[0]*i
try:
 while 1:i=s.rindex(c[j],0,i);r[i]=1;j^=1
except:print(*r)