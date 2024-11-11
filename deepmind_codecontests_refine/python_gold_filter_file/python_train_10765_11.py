n=input()
for i in range(len(n)-1,-1,-1):
    x=int(n[i])
    a=''
    if x < 5:
        a+='O-|'
    else:
        a+='-O|'
        x-=5

    t=''
    for j in range(x):
        t+='O'
    a+=t+'-'+('O'*(4-x))
    print(a)

    