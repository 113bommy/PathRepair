n=int(input())
c1=input().split()
c2=input().split()
c3=input().split()
for i in range(n):
    c1[i]=int(c1[i])
    c2[i]=int(c2[i])
    c3[i]=int(c3[i])
a=[[] for i in range(n)]
for i in range(n-1):
    u,v=map(int,input().split())
    a[u-1].append(v-1)
    a[v-1].append(u-1)
#print(a)    
count1=0
count2=0
j=0
for i in range(n):
    if(len(a[i])==1):
        j=i
        count1+=1
    if(len(a[i])==2):
        count2+=1
if(count1==2 and count2==n-2):
    b=[]
    check=[0 for i in range(n)]
    while len(b)<n:
        b.append(j)
        check[j]=1
        if(len(b)==n):
            break
        if(check[a[j][0]]==0):j=a[j][0]
        else:j=a[j][1]
    # 6 cases
    # case 1 (1 2 3)
    ans1=0
    color1=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans1+=c1[b[i]]
            color1[b[i]]=1
        elif(i%3==1):
            ans1+=c2[b[i]]
            color1[b[i]]=2
        else:
            ans1+=c3[b[i]]
            color1[b[i]]=3
    # case 2 (3 1 2)
    ans2=0
    color2=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans2+=c3[b[i]]
            color2[b[i]]=3
        elif(i%3==1):
            ans2+=c1[b[i]]
            color2[b[i]]=1
        else:
            ans2+=c2[b[i]]   
            color2[b[i]]=2
    # case 3 (2 3 1)
    ans3=0
    color3=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans3+=c2[b[i]]
            color3[b[i]]=2
        elif(i%3==1):
            ans3+=c3[b[i]]
            color3[b[i]]=3
        else:
            ans3+=c1[b[i]]
            color3[b[i]]=1
    # case 4 (1 3 2)
    ans4=0
    color4=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans4+=c1[b[i]]
            color4[b[i]]=1
        elif(i%3==1):
            ans4+=c3[b[i]]
            color4[b[i]]=3
        else:
            ans4+=c2[b[i]]
            color4[b[i]]=2
    # case 5 (3 2 1)
    ans5=0
    color5=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans5+=c3[b[i]]
            color5[b[i]]=3
        elif(i%3==1):
            ans5+=c2[b[i]]
            color5[b[i]]=2
        else:
            ans5+=c1[b[i]]   
            color5[b[i]]=1
    # case 6 (2 1 3)
    ans6=0
    color6=[0 for i in range(n)]
    for i in range(n):
        if(i%3==0):
            ans6+=c2[b[i]]
            color6[b[i]]=2
        elif(i%3==1):
            ans6+=c1[b[i]]
            color6[b[i]]=1
        else:
            ans6+=c3[b[i]]  
            color6[b[i]]=3
    if(ans1==min(ans1,ans2,ans3,ans4,ans5,ans6)):
        print(ans1)
        print(*color1)
    elif(ans2==min(ans1,ans2,ans3,ans4,ans5,ans6)):
        print(ans2)
        print(*color2)
    elif(ans3==min(ans1,ans2,ans3,ans4,ans5,ans6)):
        print(ans3)
        print(*color3)
    elif(ans4==min(ans1,ans2,ans3,ans4,ans5,ans6)):
        print(ans4)
        print(*color4)
    elif(ans5==min(ans1,ans2,ans3,ans4,ans5,ans6)):
        print(ans5)
        print(*color5)
    else:
        print(ans6)
        print(*color6)
else:
    print(-1)