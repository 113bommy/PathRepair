t=int(input())
for i in range(t):
    s=int(input())
    ans=0
    while s>=10:
        ans+=10*(s//10)
        s = s%10 + s//10
    ans+=s
    print(ans)
    