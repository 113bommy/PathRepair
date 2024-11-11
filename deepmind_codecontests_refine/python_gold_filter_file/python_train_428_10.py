n=int(input())

for i in range(n):
    
    x=int(input())
    s=input()
    s1=s
    s2=s
    count=0
    if len(s)==1:
        print(0)
    else:    
        while(s2[0]!=">") and (s1[len(s1)-1]!="<"):
            
            
            s1=s1[0:len(s1)-1]
            s2=s2[1:len(s2)]
            count+=1
            
        print(count)                   
                       



                       
