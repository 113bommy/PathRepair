n=int(input())
taxiarray=[]
pizzaarray=[]
randiarray=[]
ppl=[]
for i in range(n):
	m,name=input().split()
	m=int(m)
	randi=taxi=pizza=0
	for j in range(m):
		phno=list(input())
		phno.remove('-')
		phno.remove('-')
		temp=set(phno)
		if len(temp)==1:
			taxi+=1
		else:
			flag=1
			for k in range(len(phno)-1):
				if phno[k]<=phno[k+1]:
					flag=0
					break
			if flag==1:
				pizza+=1
			else:
				randi+=1
	taxiarray.append(taxi)
	pizzaarray.append(pizza)
	randiarray.append(randi)
	ppl.append(name)
mtaxi=max(taxiarray)
mpizza=max(pizzaarray)
mrandi=max(randiarray)
twala=[]
pwala=[]
rwala=[]
for i in range(n):
	if taxiarray[i]==mtaxi:
		twala.append(ppl[i])
	if pizzaarray[i]==mpizza:
		pwala.append(ppl[i])
	if randiarray[i]==mrandi:
		rwala.append(ppl[i])
line1='If you want to call a taxi, you should call: '+twala[0]
for i in range(1,len(twala)):
	line1=line1+', ' +twala[i]
line1=line1+'.'
line2='If you want to order a pizza, you should call: '+pwala[0]
for i in range(1,len(pwala)):
	line2=line2+', ' +pwala[i]
line2=line2+'.'
line3='If you want to go to a cafe with a wonderful girl, you should call: '+rwala[0]
for i in range(1,len(rwala)):
	line3=line3+', ' +rwala[i]
line3=line3+'.'
print(line1)
print(line2)
print(line3)