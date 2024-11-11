def srk(s,n):
    for i in range(n//2):
        if s[i]==s[n-i-1]:
            continue
        elif abs(ord(s[i])-ord(s[n-i-1]))==2:
            continue
        else:
            return 0
    return 1
    
t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    p=srk(s,n)
    if p==1:
        print("YES")
    else:
        print("NO")