hora=["00","01","02","03","04","05","10","11","12","13","14","15","20","21","22","23"]
minutos=["00","10","20","30","40","50","01","11","21","31","41","51","02","12","22","32"]
b=input()
b=b.split(":")
b[0]=int(b[0])
b[1]=int(b[1])
for k in range (len(hora)):
        if int(hora[k])>=b[0]:
                if int(hora[k])==b[0]:
                        if (int(minutos[k])>b[1]):
                                posicion=k
                                break
                        else:
                                if k<((len(hora))-1):
                                        posicion=k+1
                                        break
                                else:
                                        posicion=0
                                        break
                else:
                        posicion=k
                        break
print(hora[posicion]+":"+minutos[posicion])