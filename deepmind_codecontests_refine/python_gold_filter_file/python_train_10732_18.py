n,m=map(int,input().split())
s=input()
t=input()
if(len(s)-1>len(t)):print("NO")
else:
    if(s[0]=='*'):
        if(s[1:n]==t[m-n+1:m]):print("YES")
        else:print("NO")
    elif("*" not in s):
        if(s==t):print("YES")
        else: print("NO")
    else:
    
        star=s.index('*')
        #print(star)
        if(s[0:star]!=t[0:star]):print("NO")
        else:
            if(s[star+1:n]!=t[m-n+star+1:m]):print("NO")
            else:print("YES")