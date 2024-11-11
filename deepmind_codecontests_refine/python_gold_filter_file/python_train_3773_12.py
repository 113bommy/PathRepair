t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort(reverse=True)
    ll=[]
    p=0
    q=n-1
    
    while(p<q):
        ll.append(l[p])
        ll.append(l[q])
        p+=1
        q-=1
    if n%2!=0:
        ll.append(l[p])
    ll.reverse()
    print(*ll)
        
    
    