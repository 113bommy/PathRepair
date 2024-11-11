s=list(input())
s[0]=str(ord(s[0])-96)
if(s[0]=='1' and s[1]=='1'):
    print(3)
elif(s[0]=='8' and s[1]=='1'):
    print(3)
elif(s[0]=='1' and s[1]=='8'):
    print(3)
elif(s[0]=='8' and s[1]=='8'):
    print(3)
elif(s[0]=='1' or s[1]=='1' or s[0]=='8' or s[1]=='8'):
    print(5)
else:
    print(8)