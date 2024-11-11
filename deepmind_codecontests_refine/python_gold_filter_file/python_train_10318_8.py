n=int(input())
l=list(map(int,input().split()))
ans=[0]*n
check=[0]*(101) 
for i in range(n):
    check[l[i]]+=1 
once=0 
for i in range(101):
    if check[i]==1:
        once+=1 
keep=1   
if once%2==0:
    print("YES")
    for i in range(n):
        if check[l[i]]==1 and keep<=once//2:
            ans[i]='A'
            keep+=1
        else:
            ans[i]='B'
    print(''.join(ans))    
else:
    if max(check)<=2:
        print("NO")
    else:
        keep=1
        print("YES")
        convert=0
        for i in range(1,101):
            if check[i]>2:
                convert=i 
                break
        flag=0   
        for i in range(n):
            if check[l[i]]==1 and keep<=once//2:
                ans[i]='A'
                keep+=1
            elif l[i]==convert and flag==0:
                ans[i]='A'
                flag=1
            else:
                ans[i]='B'
        print(''.join(ans))            
                
                