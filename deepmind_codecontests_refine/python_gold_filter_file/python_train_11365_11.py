
def ab(n,p,q):
    ans=-1
    #print(p,q)
    x=min(len(p),len(q))
    if(q[0]!='0'):
        ans=(int(p)+int(q))
        #print(ans)
        return ans
    for i in range(x-1):
        #print(i)
        if(p[len(p)-i-1]!='0' and q[i+1]!='0'):
            return min(int(p[:len(p)-1-i])+int(p[len(p)-1-i:]+q),int(p+q[:i+1])+int(q[i+1:]))
        if(p[len(p)-1-i]!='0'):
            return int(p[:len(p)-1-i])+int(p[len(p)-1-i:]+q)
        if(q[i+1]!='0'):
            #print(p+q[:i+1],q[i+1:])
            return int(p+q[:i+1])+int(q[i+1:])
    return int('9'*n)
        
t=1
while(t):
    t-=1
    n=int(input())
    s=input()
    if(n%2==0):
        p=s[:n//2]
        q=s[n//2:]
        print(ab(n,p,q))

    else:
        p=s[:n//2+1]
        q=s[n//2+1:]
        p1=s[:n//2]
        q1=s[n//2:]
        print(min(ab(n,p,q),ab(n,p1,q1)))
        
