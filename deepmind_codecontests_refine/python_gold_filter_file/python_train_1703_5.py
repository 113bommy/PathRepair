n, k = map(int, input().split())
s = input()
l = []
ans = 0
if(k == 2):
    s1 = []
    s2 = []
    for i in range(n):
        if(i&1):
            s1.append('A')
            s2.append('B')
        else:
            s2.append('A')
            s1.append('B')
            
    a1 = 0
    a2 = 0
    for i in range(n):
        if(s[i]!= s1[i]):
            a1+=1
        if(s[i]!= s2[i]):
            a2+=1
            
    
    if(a1>a2):
        print(a2)
        print(("").join(s2))
    else:
        print(a1)
        print(("").join(s1))
            

else:
            
    for i in range(n):
        if(len(l) == 0):
            l.append(s[i])
        else:
            if(l[-1] == s[i]):
                if(i!=n-1):
                    a = l[-1]
                    b = s[i+1]
                    if(a == b):
                        if(a== 'A'):
                            l.append('B')
                        else:
                            l.append('A')
                    else:
                        if(a == 'A' and b != 'B'):
                            l.append('B')
                        elif(a == 'A' and b == 'B'):
                            
                            
                            l.append('C')
                        elif(a != 'B' and b == 'A'):
                            l.append('B')
                        elif(a == 'B' and b == 'A'):    
                            
                            l.append('C')
                        else:
                            l.append('A')
                            
                else:
                    if(l[-1]== 'A'):
                        l.append('B')
                    else:
                        l.append('A')
                ans+=1
                        
            else:
                l.append(s[i])
                    
                        
    print(ans)
    print(("").join(l))
                    
    