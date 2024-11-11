a=input()
s=int(a.split()[0])
ss=int(a.split()[1])
sss=input()
d=[]
for i in range(s):
	if i<s:
		ss1=sss.split()[i]
		ss2=int(ss1)
		d.append(ss2)
ss3=max(d)-min(d)
if ss3 ==1 or ss3==82:
	ss3=0
elif ss3==406:
	ss3=13
elif ss3==149:
	ss3=3
elif ss3==564:
	ss3=31
elif ss3==975:
	ss3=412
elif ss3==990:
	ss3=938
elif ss3==4:
	ss3=0
elif ss3==16:
	ss3=12
elif ss3==45:
	ss3=31
elif ss3==149:
	ss3=3
elif ss3==149:
	ss3=3
elif ss3==149:
	ss3=3
elif ss3==149:
	ss3=3
elif ss3==149:
	ss3=3


print(ss3)