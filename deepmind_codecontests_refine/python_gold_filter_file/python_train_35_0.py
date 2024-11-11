s=input()
temp=[]
tem=[]
c=0
mon=[31,28,31,30,31,30,31,31,30,31,30,31]
f={}
for i in range(len(s)-10+1):
    x=s[i:i+10]
    if x[2]=='-' and x[5]=='-' and x.count('-')==2:
        #print(i)
        y=int(x[0:2])
        yy=int(x[3:5])
        yyy=int(x[-4:])
        #print(y,yy,yyy)
        if yyy>=2013 and yyy<=2015:
            if yy>=1 and yy<=12:    
                if y<=mon[yy-1] and y>=1:
                    try:
                        f[x]+=1
                    except:
                        f[x]=1

ff={v:k for k,v in f.items()} 
print(ff[max(ff.keys())])                                         