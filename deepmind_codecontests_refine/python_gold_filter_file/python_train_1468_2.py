s=input().strip()
s=s.lower()
last=s[-1]
flag=1
if(last=='a' or last=='e' or last=='i' or last=='o' or last=='u' or last=='n'):
    for i in range(0, len(s)-1):
        if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u' and s[i]!='n'):
            if(s[i+1]=='a' or s[i+1]=='e' or s[i+1]=='i' or s[i+1]=='o' or s[i+1]=='u'):
                continue
            else:
                flag=0
                break
        else:
            continue
else:
    flag=0
if(flag==0):
    print("NO")
if(flag==1):
    print("YES")
