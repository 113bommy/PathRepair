#!usr/bin
import math
if __name__=="__main__":
    u, v=map(int, input().split()) 
    if v!=0: #
        k=math.ceil(math.log2(v))
    if u==0 and v==0:
        print(0)
        exit(0)
    if u==v: #
        print(1)
        print(v)
        exit(0)
    if u>v or (u^v)&1==1:
        print(-1)
    else:
        carry=0
        able=True
        a=b=0
        for i in range(k+1):#+1wei
            xor=(u>>i)&1
            sum=(v>>i)&1
            if carry==0:
                if sum^xor==1:
                    able=False
                    break
                elif sum==1:
                    a=a|(1<<i)
                    b=b&~(1<<i)
                else:
                    carry=1
            elif carry==2:
                if sum^xor==0:
                    able=False
                    break
                elif xor==1:
                    a=a|(1<<i)
                    b=b&~(1<<i)
                    carry=2
                else:
                    carry=1
            else:
                if xor^sum==0:
                    a=a&~(1<<(i-1))
                    b=b&~(1<<(i-1))
                else:
                    a=a|(1<<(i-1))
                    b=b|(1<<(i-1))
                if xor==1:
                    a=a|(1<<i)
                    b=b&~(1<<i)
                    if sum==0: #
                        carry=2
                    else:
                        carry=0
                else:
                    carry=1
                
        if able==True:
            print(2)
            print("%d %d"%(a,b))
        else:
            v = v-u
            for i in range(k):
                if (v>>(i+1))&1==1:
                    v=v|(1<<i)
                elif (v>>i)&1==1:
                    v=v^(1<<i)
            print(3)
            print(" ".join((str(i) for i in (u,v,v))))
