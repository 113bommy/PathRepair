# your code goes here
a = int(input())
s = input()
count = 0
m1 = '0'
m2 = '0'
for i in range(len(s)):
	if(  (m1=='0')and(m2=='0') ):
		m1=s[i]
		
	if(  (m1!=s[i])and(m2!=s[i])and(m1!='0')and(m2!='0')  ):
		count+=1
		m1=s[i]
		m2='0'
	
	elif(  (m1!=s[i]and(m2!=s[i]))and((m1!='0')and(m2=='0'))  ):
		m2=s[i]
	if(((m1=='R') and (m2=='L'))or((m1=='L') and (m2=='R'))or((m1=='U') and (m2=='D'))or((m1=='D') and (m2=='U'))):
		count+=1
		m1=s[i]
		m2='0'
#if((s.count('R')==s.count('L'))and(s.count('D')==s.count('U'))):
	#count+=1
if(len(s)==1):
	print(1)
else:
	print(count+1)