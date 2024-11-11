n = int(input())
l = input()

comp =0
comp1=0
for i in l :
	if i=='n' :
		comp1+=1
	elif i=='z' :
		comp+=1
	
print(comp1*'1 '+comp*'0 ')
