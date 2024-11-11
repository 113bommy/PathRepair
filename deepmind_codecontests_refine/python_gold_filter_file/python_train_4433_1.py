import sys

n=int(input())
txtInit=input() #Ya es una lista
txt=list(txtInit)
genCant = [0,0,0,0]
posPre=[]
genFaltante=[0]*4
letras= ['A', 'G', 'C', 'T']
#print(txt[0])
if n%4!=0:
    print('===')
#elif '?' not in txt:
#    print(''.join(txt))
else:
    #Lleno gen con la cantidad de letras
    i=0
    for x in range(0,len(txt)):
        if txt[x]=='A':
            genCant[0]+=1
        elif txt[x]== 'G':
            genCant[1]+=1
        elif txt[x]=='C':
            genCant[2]+=1
        elif txt[x]== 'T':
            genCant[3]+=1
        else:
            posPre.append(x)
            i=i+1
    #print("gen cantidad: ",genCant)
    #print("posicion de las preguntas: ",posPre)
    #print("cantidad de preguntas: ", len(posPre))
    #Calculo genFaltante para ver si su suma me da el len(posPre)
    for x in range(0,4):
        genFaltante[x]= max(genCant)-genCant[x]
    #print("Cuantos faltan de cada letra: ",genFaltante)
    if sum(genFaltante)==0 and len(posPre)>0:
        i=0
        for x in range(0,n):
            txt[x]=letras[i]
            i=i+1
            if i==4:
                i=0
        print(''.join(txt))
    elif (sum(genFaltante) - len(posPre)) <=0:
        #print("Hay sol")
        preExtra= (sum(genFaltante) - len(posPre))*-1
        #print("preguntas extra ", preExtra)
        i=0
        u=0
        for z in range(0,len(genFaltante)):
            #print(z)
            #print("i ",i)
            while genFaltante[i]>0:
                txt[posPre[u]]=letras[i]
                u=u+1
                genFaltante[i]=genFaltante[i]-1
            i=i+1
        i=0
        for x in range(0,preExtra):
            txt[posPre[u]]=letras[i]
            u=u+1
            i=i+1
            if i==4:
                i=0

        print(''.join(txt))
    else:
        print("===")
