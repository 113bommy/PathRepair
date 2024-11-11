n=int(input())
from  math import sqrt as S 
from math import log as log,ceil as upar
d={}
c=0
for i in range(2,int(S(n))+1):
    if n%i==0:
        while n%i==0:
            c+=1 
            n=n//i 
        d[i]=c 
        c=0
if n>1:
    d[n]=1 
ans=1 
for i in d.keys():
    ans*=i 
print(ans,end=' ')

father_pow=0 
for i in d.keys():
    u=upar(log(d[i])/log(2))
   # print(u)
    father_pow=max(father_pow,u)
#print(father_pow)
if(all(d[i]==2**father_pow for i in d.keys())):
    print(father_pow)
else:
    print(father_pow+1)