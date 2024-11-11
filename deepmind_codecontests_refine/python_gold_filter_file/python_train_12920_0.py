t=int(input())
for i in range(t) :
    s=input()
    c1=0;c2=0;c3=0;
    for j in s:
        if j>="a" and j<="z" :
            c1=c1+1
            k1=j
        elif j>="A" and j<="Z" :
            c2=c2+1
            k2=j
        else :
            c3=c3+1
            k3=j
        if c1>=1 and c2>=1 and c3>=1 :
            break
    #print(c1,c2,c3)
    if c1>0 :
        if c2 >0 :
            if c3 >0 :
                print(s)
                continue
            else :
                if c1!=1 :
                    s=s.replace(k1,"1",1)
                    print(s)
                    continue
                else:
                    s=s.replace(k2,"1",1)
                    print(s)
                    continue
        else :
            if c3 >0 :
                if c1!=1 :
                    s=s.replace(k1,"A",1)
                    print(s)
                    continue
                else:
                    s=s.replace(k3,"A",1)
                    print(s)
                    continue
            else :
                print("1"+"A"+s[2:])
                continue
    else :
         if c2>0:
             if c3>0 :
                 if c2!=1:
                     s=s.replace(k2,"a",1)
                     print(s)
                     continue
                 else:
                     s=s.replace(k3,"a",1)
                     print(s)
                     continue
             else :
                    print("a"+"1"+s[2:])
                    continue
         else :
             print("a"+"A"+s[2:])
             continue
             
            
    