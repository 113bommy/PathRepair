s=input()
i=0
j=len(s)-1
c=0
while i<j:
    if s[i]!=s[j]:
        c+=1
        if s[i]=="x":
            i+=1
        elif s[j]=="x":
            j-=1
        else:
            print(-1)
            break
    else:
        i+=1
        j-=1
else:
    print(c)