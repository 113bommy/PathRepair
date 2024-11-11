# Romaji
s=str(input())
flag=0
if(len(s)==1 and s[0] not in'aeioiun'  ):
    print("NO")
elif(len(s)==1 and s[0] in'aeioun'):
    print("YES")

else:    
    for i in range(0,len(s)-1):
        if(s[i] in 'aeiou' or s[i]=='n'):
            pass
        else:
            if(s[i+1] in 'aeiou'):
                pass
            else:
                flag=1
    
    if(s[len(s)-1] not in 'aeioun'):
        flag=1
    if(flag>0):
        print("NO")
    else:
         print("YES")