import sys
input=sys.stdin.readline
s=list(input().rstrip())
n=len(s)
for i in range(n):
    s[i]=int(s[i])
ans=n*(n-1)//2 # remove l=r,r=l+1
if n>=2:
    ans-=n-1
for d in range(3,13):
    for i in range(n):
        if i+d>n:
            break
        s1=s[i:i+d]
        flg=False
        for k in range(1,5):
            for st in range(d):
                if st+2*k>=d:
                    break
                if s1[st]==s1[st+k]==s1[st+2*k]:
                    flg=True
                    break
        if not flg:
            ans-=1
print(ans)