def mex(s):
    for i in range(n):
        if(i not in s):
            return i
    return n        

for u in range(int(input())):
    n=int(input())
    s=list(map(int,input().split()))
    l=[]
    out=[]
    for i in range(n):
        if(s[i]!=i):
            l.append(i)
    while(l!=[]):
        temp=mex(s)
        if(temp==n):
            s[l[0]]=n
            out.append(l[0])
            
        elif(temp in l):
            
            s[temp]=temp
            out.append(temp)
            l.remove(temp)
    print(len(out))
    for i in out:
        print(i+1,end=' ')
    print()    
            
            
            
    