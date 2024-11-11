n,a,b,c,d=map(int,input().split())
s=input()
#s=s[a:max(c,d)+1]
if ("##" in s[a-1:max(c,d)]) or (c>d and "..." not in s[b-2:d+1]):
    print("No")
else:
    print("Yes")