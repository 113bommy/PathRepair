n=int(input())
s=str(input())
flag=0
for i in range(0,len(s)-1):
    if(s[i]==s[i+1] and s[i]!='?'):
        flag=1
if(flag==1):
    print('NO')
elif(flag==0):
    if(s[0]=='?' or s[-1]=='?'):
        print('YES')
    else:
        flags=0
        for j in range(0,len(s)):
            if(s[j]=='?'):
                d=set()
                if(s[j+1]!='?'):
                    d.add(s[j+1])
                if(s[j-1]!='?'):
                    d.add(s[j-1])  
                if(len(d)==1):
                    print('YES')
                    flags=1
                    break
        if(flags==0):
            print('NO')