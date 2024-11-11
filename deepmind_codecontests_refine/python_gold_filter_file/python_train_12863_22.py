k,r=map(int,input().split())
l=0
for i in range(k,10000000, k):
    l=l+1
    if i%10==0 or (i-r)%10==0:
        print(l)
        break

        
