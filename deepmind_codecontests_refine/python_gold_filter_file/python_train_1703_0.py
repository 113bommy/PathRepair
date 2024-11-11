n,k=map(int,input().split())
s=input()
if(k==2):
    #A
    sol1=[s[i] for i in range(n)]
    ans1=0
    for i in range(n): 
        if(i%2==0 and sol1[i]=="B"):
            ans1+=1
            sol1[i]="A"
        elif(i%2!=0 and sol1[i]=="A"):
            ans1+=1
            sol1[i]="B"
    #B        
    sol2=[s[i] for i in range(n)]
    ans2=0
    for i in range(n): 
        if(i%2==0 and sol2[i]=="A"):
            ans2+=1
            sol2[i]="B"
        elif(i%2!=0 and sol2[i]=="B"):
            ans2+=1
            sol2[i]="A"   
    if(ans1<=ans2):
        print(ans1)
        print("".join(str(x) for x in sol1))
    else:
        print(ans2)
        print("".join(str(x) for x in sol2))
else:    
    s=[s[i] for i in range(n)]
    ans=0
    for i in range(1,n):
        if(s[i]==s[i-1]):
            ans+=1
            x=chr((ord(s[i-1])-65+1)%k+65)
            if(i==n-1 or s[i+1]!=x):s[i]=x
            else:
                y=chr((ord(s[i-1])-65+1+1)%k+65)
                s[i]=y
    print(ans)
    print("".join(str(x) for x in s))