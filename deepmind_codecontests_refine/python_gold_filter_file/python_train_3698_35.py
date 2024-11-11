n = int(input())
s=input()
d={}
d['G']=0
d['R']=0
d['B']=0
for i in s:
    d[i]+=1        
#print(d)   
if d['R']>=1 and d['G']>=1 and d['B']>=1:
    print("BGR")
elif (d['R']>1 and d['G']>1) or (d['G']>1 and d['B']>1) or (d['R']>1 and d['B']>1):
    print("BGR")
elif (d['R']>1 and (d['G']==1 or d['B']==1)):
    print("BG")
elif (d['B']>1 and (d['G']==1 or d['R']==1)):
    print("GR")
elif (d['G']>1 and (d['R']==1 or d['B']==1)):
    print('BR')
elif d['G']==1 and d['B']==1:
    print("R")
elif d['B']==1 and d['R']==1:
    print('G')
elif d['G']==1 and d['R']==1:
    print('B')            
elif d['G']>=1:
    print("G")
elif d['B']>=1:
    print("B")
elif d['R']>=1:
    print("R")            
