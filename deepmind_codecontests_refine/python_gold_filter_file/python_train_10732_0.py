n,m=map(int,input().split())
s=input()
t=input()
s=list(s)
t=list(t)
if "*" in s:
    p=s.index("*")+1
    q=len(s[s.index("*")+1:])
    if len(s)>(len(t)+1):
        print("NO")
    elif s[0:s.index("*")]==t[0:s.index("*")] and ((s[s.index("*")+1:])==(t[len(t)-q:len(t)])):
        print("YES")
    else:
        print("NO")
elif "*" not in s:
    if s==t:
        print("YES")
    else:
        print("NO")
