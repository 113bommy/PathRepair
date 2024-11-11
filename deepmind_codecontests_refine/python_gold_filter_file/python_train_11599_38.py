try:
    n=input()
    s=set(n)
    if (s=={'1','4'} or s=={'1'} or s=={'4'}) and n[0]=='1':
        c=0
        for i in range(1,len(n)):
            if n[i]=='4':
                c=c+1
            else:
                c=0
            if c==3:
                print("NO")
                break
        else:
             print("YES")
    else:
        print("NO")
except:
    pass

            
            
