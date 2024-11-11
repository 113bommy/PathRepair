q=int(input())
for i in range(q):
    s=''
    t=''
    n=0
    ans=0
    n=int(input())
    s=input()
    for j in range(n):
        if (int(s[j])%2==1):
            t+=s[j]
            ans+=1
    if (ans>=2):
        print(t[0]+t[1])
    else:
        print(-1)