def special(xx):
    # [[x1,y1],[x2,y2],[x3,y3],[x4,y4]]
    global ans,ar,mai
    left=3
    x1,y1=xx[0][0],xx[0][1]
    x2,y2=xx[1][0],xx[1][1]
    x3,y3=xx[2][0],xx[2][1]
    x4,y4=xx[3][0],xx[3][1]
    if(ar[x1][y1]!=0 or ar[x3][y3]!=0):
        ans+=1
        mai.append([])
        if(ar[x1][y1]!=0):
            left-=1
            mai[-1].append(x1+1)
            mai[-1].append(y1+1)
            ar[x1][y1]=0
        if(ar[x3][y3]!=0):
            mai[-1].append(x3+1)
            mai[-1].append(y3+1)
            left-=1
            ar[x3][y3]=0
        if(left!=0):
            ar[x2][y2]=abs(ar[x2][y2]-1)
            mai[-1].append(x2+1)
            mai[-1].append(y2+1)
            left-=1
        if(left!=0):
            ar[x4][y4]=abs(ar[x4][y4]-1)
            mai[-1].append(x4+1)
            mai[-1].append(y4+1)
def special2(xx):
    global ans,ar,mai
    left=3
    x1,y1=xx[0][0],xx[0][1]
    x3,y3=xx[1][0],xx[1][1]
    x2,y2=xx[2][0],xx[2][1]
    x4,y4=xx[3][0],xx[3][1]
    if(ar[x1][y1]!=0 or ar[x3][y3]!=0):
        ans+=1
        mai.append([])
        if(ar[x1][y1]!=0):
            left-=1
            mai[-1].append(x1+1)
            mai[-1].append(y1+1)
            ar[x1][y1]=0
        if(ar[x3][y3]!=0):
            mai[-1].append(x3+1)
            mai[-1].append(y3+1)
            left-=1
            ar[x3][y3]=0
        if(left!=0):
            ar[x2][y2]=abs(ar[x2][y2]-1)
            mai[-1].append(x2+1)
            mai[-1].append(y2+1)
            left-=1
        if(left!=0):
            ar[x4][y4]=abs(ar[x4][y4]-1)
            mai[-1].append(x4+1)
            mai[-1].append(y4+1)
def fun1(xx):
    # [[x1,y1],[x2,y2],[x3,y3],[x4,y4]]
    global ar,ans,mai
    zer=[]
    one=[]
    for i in xx:
        if(ar[i[0]][i[1]]==0):
            zer.append([i[0],i[1]])
        else:
            one.append([i[0],i[1]])
    ans+=2
    mai.append([])
    for i in zer:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=1
    for i in one:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=0
        break
    del one[0]
    mai.append([])
    for i in zer:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=0
    for i in one:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=0
def fun2(xx):
    global ar,ans,mai
    zer=[]
    one=[]
    for i in xx:
        if(ar[i[0]][i[1]]==0):
            zer.append([i[0],i[1]])
        else:
            one.append([i[0],i[1]])
    ans+=1
    mai.append([])
    zer.pop()
    for i in zer:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=1
    for i in one:
        mai[-1].append(i[0]+1)
        mai[-1].append(i[1]+1)
        ar[i[0]][i[1]]=0
    fun1(xx)
    
def fun3(xx):
    global ar,ans,mai
    zer=[]
    one=[]
    for i in xx:
        if(ar[i[0]][i[1]]==0):
            zer.append([i[0],i[1]])
        else:
            one.append([i[0],i[1]])
    ans+=1
    mai.append([])
    for i in one:
       mai[-1].append(i[0]+1)
       mai[-1].append(i[1]+1)
       ar[i[0]][i[1]]=0
    

for _ in range(int(input())):
    n,m=map(int,input().split())
    ans=0
    mai=[]
    ar=[]
    if(m!=2):
        for i in range(n):
            ar.append(list(map(int,list(input()))))
        for i in range(n-1):
            for j in range(m-1):
                special([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        for i in range(n-1):
            j=m-2
            special2([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        i=n-2
        j=m-2
        zero=0
        one=0
        if(ar[i][j]==0):
            zero+=1
        else:
            one+=1
        if(ar[i+1][j]==0):
            zero+=1
        else:
            one+=1
        if(ar[i][j+1]==0):
            zero+=1
        else:
            one+=1
        if(ar[i+1][j+1]==0):
            zero+=1
        else:
            one+=1
        if(one==2 and zero==2):
            fun1([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        elif(zero==3 and one==1):
            fun2([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        print(ans)
        for i in mai:
            print(*i)
    else:
        for i in range(n):
            ar.append(list(map(int,list(input()))))
        for i in range(n-1):
            for j in range(m-1):
                zero=0
                one=0
                if(ar[i][j]==0):
                    zero+=1
                else:
                    one+=1
                if(ar[i+1][j]==0):
                    zero+=1
                else:
                    one+=1
                if(ar[i][j+1]==0):
                    zero+=1
                else:
                    one+=1
                if(ar[i+1][j+1]==0):
                    zero+=1
                else:
                    one+=1
                if(one==4):
                    ans+=1
                    mai.append([])
                    mai[-1].append(i+1)
                    mai[-1].append(j+1)
                    mai[-1].append(i+2)
                    mai[-1].append(j+1)
                    mai[-1].append(i+1)
                    mai[-1].append(j+2)
                    ar[i][j]=0
                    ar[i][j+1]=0
                    ar[i+1][j]=0
                elif(one==2 and zero==2):
                    fun1([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
                elif(zero==3 and one==1):
                    fun2([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
                elif(one==3):
                    fun3([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        zero=0
        one=0
        if(ar[i][j]==0):
            zero+=1
        else:
            one+=1
        if(ar[i+1][j]==0):
            zero+=1
        else:
            one+=1
        if(ar[i][j+1]==0):
            zero+=1
        else:
            one+=1
        if(ar[i+1][j+1]==0):
            zero+=1
        else:
            one+=1
        if(one==4):
            ans+=1
            mai.append([])
            mai[-1].append(i+1)
            mai[-1].append(j+1)
            mai[-1].append(i+2)
            mai[-1].append(j+1)
            mai[-1].append(i+1)
            mai[-1].append(j+2)
            ar[i][j]=0
            ar[i][j+1]=0
            ar[i+1][j]=0
        elif(one==2 and zero==2):
            fun1([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        elif(zero==3 and one==1):
            fun2([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        elif(one==3):
            fun3([[i,j],[i,j+1],[i+1,j],[i+1,j+1]])
        print(ans)
        for i in mai:
            print(*i)