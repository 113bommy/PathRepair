import sys
numcolumns,numinputs=map(int,input().split())
row1=[0]*numcolumns
row2=[0]*numcolumns
blocks=0
answerlist=[]
for _ in range(numinputs):
    r,c=map(int,sys.stdin.readline().split( ))
    if r==1:
        row1[c-1]=(row1[c-1]+1)%2
        if row1[c-1]==1:
            if c==1:
                blocks+=1
            if row2[c-1]==1:
                blocks+=1
            if c<=numcolumns-1 and row2[c]==1:
                blocks+=1
            if c>=2 and row2[c-2]==1:
                blocks+=1
        #unplug the blocks
        elif row1[c-1]==0:
            if c==1:
                blocks+=-1
            if  row2[c-1]==1:
                blocks+=-1
            if c<=numcolumns-1 and row2[c]==1:
                blocks+=-1
            if c>=2 and row2[c-2]==1:
                blocks+=-1
    elif r==2:
        row2[c-1]=(row2[c-1]+1)%2
        if row2[c-1]==1:
            if c==numcolumns:
                blocks+=1
            if row1[c-1]==1:
                blocks+=1
            if c<=numcolumns-1 and row1[c]==1:
                blocks+=1
            if c>=2 and row1[c-2]==1:
                blocks+=1
        #unplug the blocks
        elif row2[c-1]==0:
            if c==numcolumns:
                blocks+=-1
            if row1[c-1]==1:
                blocks+=-1
            if c<=numcolumns-1 and row1[c]==1:
                blocks+=-1
            if c>=2 and row1[c-2]==1:
                blocks+=-1
    #ouputs
    if blocks>=1:
        answerlist.append("No")
    elif blocks==0:
        answerlist.append("Yes")
for b in answerlist:
    sys.stdout.write("\n"+b)