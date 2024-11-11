def substring(a,b):
        x=len(a)
        y=len(b)
        #print (a,b,x,y)
        if x>y:
            return False
        else:
            a=sorted(a)
            #print (a)
            for j in range(y):
                if (j + x - 1 >= y):
                    return False
                sr=''
                for k in range(x):
                    sr = sr + b[k+j]
                sr=sorted(sr)
                #print (sr)
                if sr==a:
                    return True    
t=int(input())
for i in range(t):
    a=str(input())
    b=str(input())
    m=substring(a,b)
    if m:
        print ("YES")
    else:
        print ("NO")
