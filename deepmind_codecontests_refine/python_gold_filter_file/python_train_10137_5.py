cantidad=input("")
numero=input("")
cantidad=int(cantidad)
if cantidad % 2==0:
	div=cantidad/2
	entrega=""
	cont=0
	while div!=0:
		entrega=entrega+str(numero[cont])+str(numero[cont+1])+'-'
		cont+=2
		div-=1
elif cantidad==3:
	entrega=str(numero)+'-'
else:
	div=int(cantidad/2)-1
	entrega=""
	cont=0
	entrega=entrega+str(numero[cont])+str(numero[cont+1])+str(numero[cont+2])+'-'
	cont+=3
	while div!=0:
		entrega=entrega+str(numero[cont])+str(numero[cont+1])+'-'
		cont+=2
		div-=1
print(entrega[:-1])


