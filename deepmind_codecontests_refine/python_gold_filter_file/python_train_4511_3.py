t=int(input())
while t:
                n=int(input())
                i=1
                if(n%2==0):
                                while(i<=n//2):
                                                print(i*2,i*2-1,end=' ')
                                                i=i+1
                else:
                                while(i<n//2):
                                                print(i*2,i*2-1,end=' ')
                                                i=i+1
                                print(i*2,n,end=" ")
                                print(i*2-1)
                t=t-1                