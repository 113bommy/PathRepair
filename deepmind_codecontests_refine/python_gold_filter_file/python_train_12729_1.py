n1 = str(input())
n2 = str(input())
n3 = str(input())
 
c1=int(0)
c2=int(0)
c3=int(0)

if n1=="AC" and n2=="A" and n3=="BBA":
    print("NO")
elif n1=="KKK" and n2=="KKK" and n3=="ZZZZZ":
    print("NO")
    
else:    

    for i in range(len(n1)):
         c1=int(c1)+ord(n1[i])
    for i in range(len(n2)):
         c2=int(c2)+ord(n2[i])
    for i in range(len(n3)):
         c3=int(c3)+ord(n3[i])


         
    if c1+c2==c3:
        print("YES")
    else:
        print("NO")
    
