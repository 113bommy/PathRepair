# PREFUNCS
def inline():
    return [ int(e) for e in input().split() ]

def outline(l):
    for e in l: print(e, end=" ")
    print()

def outlist(l):
    for e in l: print(e)



# FUNCTIONS
def insert(s, p, i):
    return s[:p] + i + s[p:]

def zig(a, b, x):
    z = str()
    turn = False
    if a > b:
        z += '0'
        a -= 1
        turn = True
    else: 
        z += '1'
        b -= 1
    while x > 0:
        if turn:
            z += '1'
            b -= 1
            x -= 1
            turn = not turn
        else:
            z += '0'
            a -= 1
            x -= 1
            turn = not turn
    return [a, b, z]
        


# INPUT
inp = inline()
a = inp[0]
b = inp[1]
x = inp[2]



# PROCESS
z = zig(a, b, x)
s = z[-1]

a = z[0]
b = z[1]
if a > 0:
    for i in range( len(s) ):
        if s[i] == '0':
            s = insert(s, i, '0' * a)
            break
if b > 0:
    for i in range( len(s) ):
        if s[i] == '1':
            s = insert(s, i, '1' * b)
            break    



# OUTPUT
print(s)