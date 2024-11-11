n,k=map(int,input().split())
b=list(map(int,input().split()))
s=input()
r=[]
w=[]
o=[]

for i in range(n):
    if s[i]=='W':
        w.append(b[i])
    elif s[i]=='O':
        o.append(b[i])
    else:
        r.append(b[i])
if k==1:
    print(-1)
    raise SystemExit
r=sorted(r)
w=sorted(w)
o=sorted(o)
r=r[::-1]
w=w[::-1]
o=o[::-1]
s1=0
s2=0
if len(o)!=0 and len(w)!=0 and len(o)+len(w)>=k:
    s1+=w[0]+o[0]
    j=2
    i=1
    e=1
    while j<k:
        if i==len(o) or (e<len(w) and w[e]>o[i]):
            s1+=w[e]
            e+=1
        else:
            s1+=o[i]
            i+=1
        j+=1
if len(o)!=0 and len(r)!=0 and len(o)+len(r)>=k:
    s2+=o[0]+r[0]
    j=2
    i=1
    e=1
    while j<k:
        if i==len(o) or (e<len(r) and r[e]>o[i]):
            s2+=r[e]
            e+=1
        else:
            s2+=o[i]
            i+=1
        j+=1
if max(s1,s2)==0:
    print(-1)
else:
    print(max(s1,s2))
