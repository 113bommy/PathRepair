import math
n=int(input())
for i in range(n) :
    w=int(input())
    s=bin(w)[2:]
    if s.count("0")!=0 :
        s=s.replace('0','1')
        print(int(s,2))
    else :
        for e in range(2,int(math.sqrt(w))+1):
            if w%e==0:
                print(w//e)
                break
        else:
            print(1)
        
