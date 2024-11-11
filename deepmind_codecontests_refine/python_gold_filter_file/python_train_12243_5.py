date = input()
hours = int(date[0:2])
h_1 = int(date[0:1])
h_2 = int(date[1:2])
m = int(date[3:5])
k=0


while((h_2*10+h_1)!=m):
	m=m+1
	k=k+1
	if(m%60==0):
		m=0 
		hours = (hours+1)%24
		h_1 = int(hours/10)
		h_2 = hours%10


print(k)