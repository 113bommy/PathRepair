s=input()
for i in range(len(s)-1,-1,-1):
    if (ord(s[i])>=65 and ord(s[i])<=90) or (ord(s[i])>=97 and ord(s[i])<=122):
        if(s[i]=='A'):
            print("YES")
        elif(s[i]=='E'):
            print("YES")
        elif(s[i]=='I'):
            print("YES")
        elif s[i]=='O':
            print("YES")
        elif s[i]=='U':
            print("YES")
        elif s[i]=='Y':
            print("YES")
        elif s[i]=='a':
            print("YES")
        elif s[i]=='e':
            print("YES")
        elif s[i]=='i':
            print("YES")
        elif s[i]=='o':
            print("YES")
        elif s[i]=='u':
            print("YES")
        elif s[i]=='y':
            print("YES")
        else:
            print("NO")
        break