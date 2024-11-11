def process(s, t):
    l=[]
    r=[0]*len(t)
    j=0
    for i in range(len(t)):
        while s[j]!=t[i]:
            j+=1
        l.append(j)
        j+=1
    j=len(s)-1
    for i in reversed(range(len(t))):
        while s[j]!=t[i]:
            j-=1
        r[i]=j
        j-=1
    res=max(r[0], len(s)-1-l[-1])
    for i in range(len(t)-1):
        res=max(res, r[i+1]-l[i]-1)
    return res
s=input()
t=input()
print(process(s,t))