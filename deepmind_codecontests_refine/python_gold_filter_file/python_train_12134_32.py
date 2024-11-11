for _ in range(1):
        n=int(input())
        # n,k=map(int,input().split())
        a=list(map(int,input().split()))
        mn=1
        mx=1
        i=0
        while(i<n-1):
                if(a[i]<a[i+1]):
                        mn=mn+1
                        i=i+1
                else:
                        i=i+1
                        mn=1    
                if(mn>mx):
                        mx=mn
        print(mx)                