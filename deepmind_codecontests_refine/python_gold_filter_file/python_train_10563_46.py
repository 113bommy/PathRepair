n,m=input().split(' ')
n=int(n)
m=int(m)
mylib={}
for i in range(m):
    string=input().split(' ')
    mylib.update({string[0]:string[1]})
letter=input().split(' ')
for i in range(len(letter)):
    if len(letter[i])<=len(mylib.get(letter[i])):
        print(letter[i],end=' ')
    else: print(mylib.get(letter[i]),end=' ')