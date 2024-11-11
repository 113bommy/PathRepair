n=int(input())
l1=list(map(int,input().split()))
for i in range(1,len(l1)):
    l1[i]=l1[i]+l1[i-1]
q=int(input())
for i in range(q):
    n,m=map(int,input().split())
    if(n==1):
        print(l1[m-1]//10)
    else:
        print((l1[m-1]-l1[n-2])//10)
        
    
    
    