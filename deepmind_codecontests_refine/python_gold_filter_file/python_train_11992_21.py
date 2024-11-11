n=int(input())
s=input()
a={'z':0,'e':0,'r':0,'o':0,'n':0}
for i in s:
    a[i]+=1
mx=a['e']
if a['o']<mx:
    mx=a['o']
if a['z']>=a['r']:
    a['z']=a['r']
else:
    a['r']=a['z']
n0,n1=0,0
if a['n']<=mx:
    n1=a['n']
    mx-=a['n']
    if a['z']<=mx:
        n0=a['z']
    else:
        n0=mx
else:
    n1=mx
    mx=0
an=""
for i in range(n1):
    an+="1 "
for i in range(n0):
    an+="0 "
print(an[:-1])