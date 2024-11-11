n = int(input())
li = []
for i in range(n):
    strr = input()
    if(len(strr)>10):
        li.append((strr[0] +  str((len(strr) -2 ) )+strr[len(strr)-1]))
    else:
        li.append(strr)
for i in li:
    print(i)
