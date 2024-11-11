def solve (n,k) :
    k.sort()
    mid = n//2
    state = 0
    if n%2 == 0 :
        pointer1 = mid-1
        pointer2 = mid
    else :
        pointer1 = mid-1
        pointer2 = mid+1
        
        diff1 = abs(k[pointer1]-k[mid])
        diff2 = abs(k[pointer2]-k[mid])
        
        if diff2 > diff1 :
            print (k[mid],k[pointer1],k[pointer2],end=" ")
            
        else :
            print (k[mid],k[pointer2],k[pointer1],end=" ")
            state = 1
        pointer1 -= 1
        pointer2 += 1
    
    while pointer1 >= 0 and pointer2 < n :
        if state == 0 :
            print(k[pointer1],k[pointer2],end=" ")
            
        else :
            print(k[pointer2],k[pointer1],end=" ")
            
        pointer1 -= 1
        pointer2 += 1
    
    print("")
    
        
        
              

n = int(input())

for x in range(n) :
    x = int(input())
    seq2 = list(map(int,input().split()))

    solve(x,seq2)
            


    


    
   