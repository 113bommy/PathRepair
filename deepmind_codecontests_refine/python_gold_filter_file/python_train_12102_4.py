#https://codeforces.com/contest/1348/submission/78722056
t=int(input())
while t>0 :
    t-=1
    nk=input().split()
    n=int(nk[0])
    k=int(nk[1])
    list1 = [] 
    dict1 = {}
    num=input().split()
    for i in range (0,n):
        list1.append(int(num[i]))
        p=num[i]
        if p in dict1 :
            dict1[p] +=1
        else:
            dict1[p] =1
    
    ans = []
    for i in dict1:
        ans.append(i)
    
    x=len(dict1)
    if(x>k) :
        print(-1)
    else:
        for i in range(1,n+1):
            if(k==x):
                break
            if i not in dict1 :
                ans.append(i)
                x+=1
        
        print(k*n)
        for i in range(0,n):
            for j in range(0,len(ans)):
                print(ans[j],end=" ")
        print("",end="\n")