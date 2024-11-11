x=input()
def convert(x):
	lst=x.split(" ")
	return lst 
data=convert(x)
n=int(data[0])
p=int(data[1])
k=int(data[2])
num=[]
for i in range(1,n+1):	
	num.append(i)
res=[]
r=[">>"]
l=["<<"]
for i in range(p-k,p+k+1):
	if i>0 and len(num)>=i:
		res.append(num[i-1])
if res[0]==1 and res[len(res)-1]==n:
	ans=listToStr = ' '.join([str(elem) for elem in res])
	an=ans.replace(str(p),("("+str(p)+")"),1)
elif res[0]==1:
	ans=listToStr = ' '.join([str(elem) for elem in (res+r)]) 
	an=ans.replace(str(p),("("+str(p)+")"),1)
elif res[len(res)-1]==n:
	ans=listToStr = ' '.join([str(elem) for elem in (l+res)]) 
	an=ans.replace(str(p),("("+str(p)+")"),1)
else:
	ans=listToStr = ' '.join([str(elem) for elem in (l+res+r)]) 
	an=ans.replace(str(p),("("+str(p)+")"),1)
print(an)
