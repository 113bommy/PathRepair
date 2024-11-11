import math
 
for q in range(int(input())):
    #n = int(input())
    n, m, k= list(map(int, input().split()))                                       
    k-=1
    temp2 = n*(n-1)//2
    temp =temp2-m
    temp = temp+1 if m!=n-1 else n-1
    #print(temp ,k)
    if n==1 and k>0 and m==0:
        print("YES")
    elif m>temp2:
        print("NO")
    
    elif m==temp2 and k>1:
        print("YES")
    elif  m==n-1 and k>2:
        print("YES")
    elif m<n-1:
        print("NO")
    elif 2<k:
        print("YES")
    else:
        
        
        print("NO")