t=int(input())                    
for _ in range(t):
    i,k=map(int,input().split())          
    ans=['a']*i                   
    anss=''		
    for n in range(1,i):
        if (k<=n):                   
            ans[i-n-1]='b'
            break
        else:
            k-=n
    ans[-k]='b'                 
    print(anss.join(ans))              
