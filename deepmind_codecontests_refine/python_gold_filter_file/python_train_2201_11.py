ha=list(map(int,input().split(':')))
hb=list(map(int,input().split(':')))
h1,m1=ha[0],ha[1]
h2,m2=hb[0],hb[1]
a=h1*60+m1
b=h2*60+m2
c=(a+b)//2
d=c%60
c=c//60
c=str(c)
d=str(d)
s=''
if len(c)==1:
	s+='0'+c
else:
	s+=c
if len(d)==1:
	s+=':'+'0'+d
else:               
	s+=':'+d
print(s)