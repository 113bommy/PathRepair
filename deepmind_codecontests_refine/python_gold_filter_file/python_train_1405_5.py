import sys
n=int(input())
l=list(map(int,input().split()))
lenn=len(l)-1
temp=0
if n==1:
    print("Yes")
else:
    for k in range(n):
        temp=0
        for i in range(len(l)):
            #print(i%2)
            if(i%2!=0):
                #print("d")
                l[i]=l[i]-1
                if(l[i]<0):
                    l[i]=n-1
            else:
                #print("k")
                l[i]=l[i]+1
                if l[i]==n:
                    l[i]=0
            #print("      ",l)
        for j in range (1,n):
            if l[j-1]<l[j]:
                temp+=1
            else:
                break
        #print("temp",temp)
        if(temp==n-1):
            print("Yes")
            break
        if(k==n-1):
            print("No")




         
        
        
        



    