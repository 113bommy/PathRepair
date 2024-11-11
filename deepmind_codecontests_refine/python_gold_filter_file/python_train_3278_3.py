s=input()
flag=0
for i in range(len(s)-1,-1,-1):
    tmp=int(s[i])
    if(tmp%8==0):
        print("YES")
        print(int(tmp))
        flag=1
        break
    for j in range(i-1,-1,-1):
        tmp=10*int(s[j])+int(s[i])
        if(tmp%8==0):
            print("YES")
            print(int(tmp))
            flag=1
            break
        for k in range(j-1,-1,-1):
            if(s[k]=='0'):
                continue
            tmp=100*int(s[k])+10*int(s[j])+int(s[i])
            if(tmp%8==0):
                print("YES")
                print(int(tmp))
                flag=1
                break
        if(flag==1):
            break
    if(flag==1):
        break
            
if(flag==0):
    print('NO')
