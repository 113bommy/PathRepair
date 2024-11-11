ch=input()
ls=ch.split('/')
while "" in ls :
    ls.remove("")
if ls==[]:
    print('/')
else :
    str='/'.join(ls)
    print('/'+str)