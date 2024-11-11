question = input()

dic = {'A':1,'E':1,'I':1,'O':1,'U':1,'Y':1,'a':1,'e':1,'i':1,'o':1,'u':1,'y':1}

i = len(question)-2
while question[i] == " " and i >= 0:
    i -= 1
if i >=0:
    if question[i] in dic:
        print('YES')
    else:
        print('NO')