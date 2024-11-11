n,k=map(int,input().split())
s=input()
l=[chr(65+i)for i in range(k)]
p=0
if k==2:
    q="AB"*(n//2)+"A"*(n%2)
    w="BA"*(n//2)+"B"*(n%2)
    o=0
    for i in range(n):
        if s[i]!=q[i]:p+=1
        if s[i]!=w[i]:o+=1
    if p>o:print(o,"\n",w)
    else:print(p,"\n",q)
else:
    s=list(s+"0")
    for i in range(1,n):
        if s[i]==s[i-1]:
            k=s[i]
            for j in l:
                if s[i-1]!=j and s[i+1]!=j:s[i]=j;p+=1;break
    print(p,"\n","".join(s[:-1]))