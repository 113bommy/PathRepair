'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''

def fun(l):
    mins =10000000
    a=0
    b=0
    s=0
    d={}
    d[1]=0
    d[2]=0
    d[3]=0
    while(a< len(l) and b < len(l) and b>=0):
        d[l[a]]+=1
        if(d[1]>0 and d[2] >0 and d[3]>0 and (a< len(l) and b < len(l)) and  b>=0 ):
            #print(a,b , d)
            s = a-b
            #print(a,b)
            mins = min(mins,s)
            while(d[1]>0 and d[2] >0 and d[3]>0  and (a< len(l) and b < len(l)) and b>=0 ):
                
                s=a-b 
                mins = min(mins,s)
                b+=1
                d[l[b-1]]-=1
        a+=1 
    if mins ==10000000:
        return 0 
    else:
        return mins+1
    
    
    

t= int(input())
for _ in range(t):
    l =  [int(x) for x in input()]
    ans = fun(l)
    print(ans)
    
