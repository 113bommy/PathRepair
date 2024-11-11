
for i in range(int(input())):
    n=int(input())
    s=input()
    if '<' not in s or '>' not in s:
        print(n)
    else:
        ans=0
        for i in range(n):
            if s[i]=='-' or s[(i+n-1)%n]=='-':
                ans+=1
        print(ans)
        