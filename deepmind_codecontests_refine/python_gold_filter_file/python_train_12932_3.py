import math
for _ in range(int(input())):
    s=input()
    key=[]
    point=-1
    flag=0
    for i in s:
        if(len(key)<2):
            key.append(i)
            point+=1
        else:
            if (len(key)-2)>=point and key[point+1]==i :
                point+=1
            elif point>0 and key[point-1]==i:
                point-=1
            elif point==0 and i not in key:
                key.insert(0,i)
                point=0
            elif point==len(key)-1 and i not in key:
                key.append(i)
                point+=1
            else:
                flag=1
                break
    alphabet="abcdefghijklmnopqrstuvwxyz"
    key.reverse()
    if(flag==1):
        print("NO")
    else:
        print("YES")
        for i in alphabet:
            if i not in key:
                key.append(i)
        print("".join(key))
        
                