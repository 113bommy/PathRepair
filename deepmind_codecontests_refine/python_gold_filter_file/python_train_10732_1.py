n,m=map(int,input().split())
s=input()
t=input()
k=0
j=0
if(s.count("*")==0 ):
    if(t==s):
        print("YES")
    else:
        print("NO")
else:
    k=s.find("*")
    l=s[k+1:]
    q=t[k:]
    if(t[:k]==s[:k] and q[::-1].find(l[::-1])==0):
        print("YES")
    else:
        print("NO")
