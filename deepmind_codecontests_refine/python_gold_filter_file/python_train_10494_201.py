n,a,b,c,d=map(int,input().split())
s="0"+input()
x=s[a:c+1]
y=s[b:d+1]
if "##" in s[a:c+1]:
    print("No")
    exit()

if "##" in s[b:d+1]:
    print("No")
    exit()

if c>d:
    if not "..." in s[b-1:d+2]:
        print("No")
        exit()
    
print("Yes")