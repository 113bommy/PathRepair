x=input()
y=input()
z=''
for i in range(len(x)):
    if x[i]==y[i]:
        if x[i]=='a':
            z+='b'
        elif x[i]=='b':
            z+='c'
        elif x[i]=='c':
            z+='d'
        elif x[i]=='d':
            z+='e'
        elif x[i]=='e':
            z+='f'
        elif x[i]=='f':
            z+='g'
        elif x[i]=='g':
            z+='h'
        elif x[i]=='h':
            z+='i'
        elif x[i]=='i':
            z+='j'
        elif x[i]=='j':
            z+='k'
        elif x[i]=='k':
            z+='l'
        elif x[i]=='l':
            z+='m'
        elif x[i]=='m':
            z+='n'
        elif x[i]=='n':
            z+='o'
        elif x[i]=='o':
            z+='p'
        elif x[i]=='p':
            z+='q'
        elif x[i]=='q':
            z+='r'
        elif x[i]=='r':
            z+='s'
        elif x[i]=='s':
            z+='t'
        elif x[i]=='t':
            z+='u'
        elif x[i]=='u':
            z+='v'
        elif x[i]=='v':
            z+='w'
        elif x[i]=='w':
            z+='x'
        elif x[i]=='x':
            z+='y'
        elif x[i]=='y':
            z+='z'
        elif x[i]=='z':
            z+='z'
            
    else:
        z+=y[i]
f=0
for i in range(len(z)):
    if (x[i]<y[i] and x[i]!=z[i]) or (x[i]>y[i] and y[i]!=z[i]):
        print(-1)
        f=1 
        break
if f==0:
    print(z)
       
  