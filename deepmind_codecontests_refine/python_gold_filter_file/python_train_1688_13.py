t=int(input())
for i in range(t):
    p=input()
    h=input()
    l=list(p)
    l.sort()
    ans=""
    if len(p)==len(h):
        l2=list(h)
        l2.sort()
        if l==l2:
            ans="YES"
    for i in range(len(h)-len(p)+1):
        l2=list(h[i:i+len(p)])
        l2.sort()
        if l==l2:
            ans="YES"
    if(ans!="YES"):
        ans="NO"
    print(ans)