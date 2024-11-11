import  math
str=input()
str.replace(str[-1],' ')
hour,min=map(int,str.split())
H,D,C,N=map(float,input().split())
s=0
k=math.ceil((H+((20-hour)*60-min)*D)/N)*C*0.8
n=C*math.ceil(H/N)
if((20-hour)*60-min<=0):
   s=n*0.8
elif(k<n):
    s=k
else:s=n
print(s)