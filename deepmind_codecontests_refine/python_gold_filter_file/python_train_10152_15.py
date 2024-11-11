n=input().split(" ")
x=int(n[0])
p=int(n[2])
c=0
resposta="nao"
lista=[]
while(x<=int(n[1])):
	if(resposta=="nao"):
		while(True):
			x=p**c
			c+=1
			if(int(n[0])<=x<=int(n[1])):
				resposta="sim"
				lista.append(x)
				break
			else:
				if(x>int(n[1])):
					break
	else:
		x=p**c
		c+=1
		if(x<=int(n[1])):
			lista.append(x)
if(resposta=="nao"):
	print(-1)
else:
	for t in range(len(lista)):
		if(t!=len(lista)-1):
			print(lista[t],end=" ")
		else:
			print(lista[t])