s=input()
c=0
d={'caps':0,'small':0,'digit':0}
if(len(s)<5):
    print('Too weak')
else:
    f=0
    for i in s:
        m=ord(i)
        if(d['small']==0 and m>=97 and m<=123):
            d['small']=1
            c+=1
        elif(d['caps']==0 and m>=65 and m<=91):
            d['caps']=1
            c+=1
        elif(d['digit']==0 and m>=48 and m<=57):
            d['digit']=1
            c+=1
        if(c==3):
            f=1
            break
    if(f==1):
        print('Correct')
    else:
        print('Too weak')
