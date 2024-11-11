n=int(input())
l=[int(i) for i in input().split()]
l.reverse()
n1=1
ans=[0]
mx=l[0]
if n>1:
    if l[0]<l[1]:
        ans.append(0)
    else:
        ans.append(l[0]-l[1]+1)
    while n1<n-1:
        num1=l[n1]
        num2=l[n1+1]
        mx=max(num1,l[0],mx)
        if num2<=mx:
            ans.append(mx-num2+1)
        else:
            ans.append(0)
        n1+=1
    ans.reverse()
    print(*ans)
else:
    print(0)

    
            
    
    
    


    
    

