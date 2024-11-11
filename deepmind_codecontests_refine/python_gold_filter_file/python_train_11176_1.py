a1,b1,c1=list(map(int,input().split()))
a2,b2,c2=list(map(int,input().split()))

if (a1==0 and b1==0 and c1!=0) or (a2==0 and b2==0 and c2!=0):
 c=0
 print(c)
elif (a2==0 and b2==0 and c2==0):
 c=-1
 print(c)
elif (a1==0 and b1==0 and c1==0):
 c=-1
 print(c)
 
elif (a2==1 and b2==-1 and c2==-1 and c1!=-1):
 c=-1
 print(c)
elif (a1==1 and b1==0 and c1==0) and (a2==1 and b2==0 and c2==0):
 c=-1
 print(c)
elif (a1==1 and b1==0 and c1 ==1) and (a2==-1 and b2==0 and c2==-1):
 c=-1
 print(c)

 
elif (b2==0 and b1==0 and c2!=0 and c1!=0 and a2>1):
 c=0
 print(c)
elif (b2==0 and b1==0 and c2!=0 and c1!=0):
 c=-1
 print(c)

 
elif  (a1*b2==0 and a2*b1==0) and (b1*c2==0 and b2*c1==0):
 c=0
 print(c)
elif(a1*b2==a2*b1) and (b1*c2==b2*c1):
 c=-1
 print(c)
elif(a1*b2==a2*b1) and (b1*c2!=b2*c1):
 c=0
 print(c)
else:
 c=1
 print(c)

