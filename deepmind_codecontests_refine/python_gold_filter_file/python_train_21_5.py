import sys 
t=int(sys.stdin.readline())
for _ in range(t):
    n,l,r=map(int,sys.stdin.readline().split())
    prev=0
    cur=0
    start=1
    if l==r and l==n*(n-1)+1:
        print(1)
    else:
        ans=[]
        while(True):    
            cur+=(n-start)*2
            if l<=cur:
                pos=l-prev
                total=r-l+1
                if(pos%2==1):
                    ans.append(start)
                    total-=1 
                    x=start+pos//2 +1
                    while(total>0):
                        ans.append(x)
                        if x==n:
                            start+=1 
                            if start==n:
                                start=1 
                            x=start
                        total-=1 
                        if total>0:
                            ans.append(start)
                            total-=1
                            x+=1 
                else:
                    x=start+pos//2
                    while(total>0):
                        ans.append(x)
                        if x==n:
                            start+=1 
                            if start==n:
                                start=1 
                            x=start
                        total-=1 
                        if total>0:
                            ans.append(start)
                            total-=1
                            x+=1
                break
            prev=cur
            start+=1
        print(*ans)        
            
            

    