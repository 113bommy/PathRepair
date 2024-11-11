n=input()
n = n[::-1]
for i in range(len(n)):
    x = int(n[i])
    if x<5:
        s = 'O-|'
        s+= x*'O'+'-'+(4-x)*'O'
    else:
        s = '-O|'
        x-=5
        s+= x*'O'+'-'+(4-x)*'O'
    print(s)    
