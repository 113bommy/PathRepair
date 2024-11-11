input1=(list(map(int,input().split()))) 
input2=list(map(int,input().split())) 

QofStd=input1[0] 
boolStd=[] 
outputlist=[] 
allQofmes=0 

for i in range(QofStd): 
    boolStd.append(False) 

boolStd[0]=True 

out=0 
i=0 
while True: 
    if input2[i]>0 and boolStd[i]==True: 
        out=0 
        max=0 
        indexmax=-1 
        for j in range(QofStd): 
            if max<=input2[j] and boolStd[j]==False: 
                max=input2[j] 
                indexmax=j 
        if indexmax==-1: 
            break 
        boolStd[indexmax]=True 
        outputlist.append(str(i+1)+" "+str(indexmax+1)) 
        allQofmes+=1 
        input2[i]-=1 
    else: 
        if i<QofStd-1: 
            i+=1 
        else: 
            i=0 
        if out>QofStd: 
            break 
        out+=1 

Correct=True 
for i in boolStd: 
    if i==False: 
        Correct=False 

if Correct==False: 
    print(-1) 
else: 
    print(allQofmes) 
    for i in range(len(outputlist)): 
        print(str(outputlist[i]))
