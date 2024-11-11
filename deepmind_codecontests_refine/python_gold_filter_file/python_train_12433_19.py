l =[]
crosses=0
noughts=0
onewon=0
twowon=0
for i in range(3):
    t = input()
    c=0
    n=0
    for j in t:
        if j=='X':
            crosses+=1
            c+=1
        if j=='0':
            noughts+=1
            n+=1
    if n ==3:
        twowon+=1
    if c ==3:
        onewon+=1
    l.append(t)
if abs(crosses-noughts)>1 or crosses<noughts:
    print("illegal")
    exit(0)
for i in range(3):
    if l[0][i]==l[1][i] and l[1][i]==l[2][i]:
        if l[0][i]=='X':
            onewon+=1
        if l[0][i]=='0':
            twowon+=1
if l[0][0]==l[1][1]and l[1][1]==l[2][2]:
        if l[0][0]=='X':
            onewon+=1
        if l[0][0]=='0':
            twowon+=1
if l[2][0]==l[1][1]and l[1][1]==l[0][2]:
        if l[1][1]=='X':
            onewon+=1
        if l[1][1]=='0':
            twowon+=1
if twowon+onewon>1 and crosses+noughts!=9:
    print("illegal")
    exit(0)
else:
    if twowon:
        if crosses == noughts:
            print("the second player won")
        else:
            print("illegal")
        exit(0)
    if onewon:
        if crosses > noughts:
            print("the first player won")
        else:
            print("illegal")
        exit(0)
if crosses ==noughts:
    print("first")
    exit(0)
if crosses+noughts!=9:
    print("second")
    exit(0)
print("draw")

