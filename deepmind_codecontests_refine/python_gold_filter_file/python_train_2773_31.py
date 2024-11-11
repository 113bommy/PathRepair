allwMin= int(input())
hhMm= str(input()) 

sev7= True
numOfSno=0
hh, mm = map(int,hhMm.split())

while sev7:
    hh, mm = map(int,hhMm.split())
    if(hhMm.find("7")==-1):
        numOfSno+=1
        mm-=allwMin
        if(mm<0):
            mm=60+mm
            hh-=1
            if(hh<0):
                hh=24+hh
    else:
        sev7=False
    hhMm= str(hh)+" "+str(mm)

print(numOfSno)





