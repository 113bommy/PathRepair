ch=input()
b=len(ch)
K=["A","H","I","M","O","T","U","V","X","W","Y"]
if(ch[0] in K):
    
 if (len(ch)==1):
    print("YES")
 elif(b%2==0):
    if(ch[:int(b/2)]==ch[int(b/2):][::-1]):
         p=0
         for j in range(int(b/2)+1):
            if(ch[j] in K):
                p+=1
         if(p==int(b/2)+1):
            print("YES")
         else :
            print("NO")
    else :
        print("NO")
 elif(b%2!=0):
    if(ch[:int(b/2)]==ch[int(b/2)+1:][::-1]):
         p=0
         for j in range(int(b/2)+1):
            if(ch[j] in K):
                p+=1
         if(p==int(b/2)+1):
            print("YES")
         else :
            print("NO")
    else :
        print("NO")
else:
    print("NO")
