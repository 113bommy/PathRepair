t=int(input())

mlist=list(map(int,input().split()))
mlist2=[-1]
mlist2.extend(mlist)

mlist2.append(-1)
mlist=mlist2.copy()
peaks=[]
for m in range(1,t+1):
    if mlist[m]>=mlist[m-1] and mlist[m]>=mlist[m+1]:
        peaks.append(m)

if len(peaks)==1:
    for i in range(1,t+1):
        print(mlist[i],end=" ")
else:
    sumli=[]
    for p in peaks:
        lesindex=p-1
        greindex=p+1
        sumo=mlist[p]
        still=mlist[p]
        while lesindex>=1:
            still=min(mlist[lesindex],still)
            sumo+=min(mlist[lesindex],still)
            lesindex-=1
        still=mlist[p]
        while greindex<=t:
            still=min(mlist[greindex],still)
            sumo+=min(mlist[greindex],still)
            greindex+=1
        sumli.append(sumo)
    maxindex=0
    for i in range(len(sumli)):
        if sumli[i]>sumli[maxindex]:
            maxindex=i
    peakind=peaks[maxindex]
   
    lesindex=peakind-1
    greindex=peakind+1

    still=mlist[peakind]
    mlist2[peakind]=mlist[peakind]
    while lesindex>=1:
        still=min(mlist[lesindex],still)
        mlist2[lesindex]=min(mlist[lesindex],still)
        lesindex-=1
    still=mlist[peakind]
    while greindex<=t:
            still=min(mlist[greindex],still)
            mlist2[greindex]=min(mlist[greindex],still)
            greindex+=1
    for i in range(1,t+1):
        print(mlist2[i],end=" ")
