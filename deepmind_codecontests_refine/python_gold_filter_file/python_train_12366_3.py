h,w,k=map(int,input().split())
ans=10**9
choco=[list(input()) for i in range(h)]
sumL=[[0 for i in range(w+1)] for j in range(h+1)]
for i in range(h):
    for j in range(w):
        sumL[i][j]=sumL[i-1][j]+sumL[i][j-1]-sumL[i-1][j-1]+int(choco[i][j])
for stat in range(2**(h-1)):
    cnt=0;previous=-1
    flg=0
    cut=format(stat,"b").zfill(h-1)
    cutl=[]
    for hi in range(h-1):
        if cut[hi]=="1":
            cutl.append(hi)
            cnt+=1
    cutl.append(h-1)
    cutl.append(-1)
    for yoko in range(w):
        for seg in range(len(cutl)):
            if sumL[cutl[seg]][yoko]-sumL[cutl[seg]][previous]-sumL[cutl[seg-1]][yoko]+sumL[cutl[seg-1]][previous]>k and yoko-previous<=1:flg=1
            elif sumL[cutl[seg]][yoko]-sumL[cutl[seg]][previous]-sumL[cutl[seg-1]][yoko]+sumL[cutl[seg-1]][previous]>k:previous=yoko-1;cnt+=1
            
    if not flg and cnt < ans:ans=cnt
    
print(ans)
