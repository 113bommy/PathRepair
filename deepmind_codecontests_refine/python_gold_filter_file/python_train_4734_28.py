s=input()
i=-1
while(s[i]==" " or s[i]=="?"):
    i-=1
if(s[i]=="a" or s[i]=="e" or s[i]=="i" or s[i]=="o" or s[i]=="u" or s[i]=="y" or s[i]=="A" or s[i]=="E" or s[i]=="I" or s[i]=="O" or s[i]=="U" or s[i]=="Y"):
    print("YES")
else:
    print("NO")