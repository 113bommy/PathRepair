n = int(input())
d = {}
for i in range(n):
    c, name = map(str, input().split())
    l = []
    for j in range(int(c)):
        l.append(input())
    d[name] = l
l = {}
mo = ["girl", "pizza", "taxi"]
for i in d:
    l[i] = {}
    for j in mo:
        l[i][j] = 0
for i in d:
    for j in d[i]:
        flag = True
        if len(set(j)) == 2:
            l[i]["taxi"]+=1
            flag = False
            
        elif len(set(j)) == len(j)-1:
            prev = j[0]
            
            flag1 = True
            for k in range(1, len(j)):
                if j[k]!='-':
                    if prev<j[k]:
                        flag1 = False
                        break
                    else:
                        prev = j[k]
            if flag1:
                
                l[i]["pizza"]+=1
                flag = False
        if flag:
            l[i]["girl"]+=1
            
mo = ["girl", "pizza", "taxi"]
maxg = 0
maxp =0
maxt = 0
for i in l:
    for j in range(3):
        if j == 0:
            maxg= max(maxg, l[i][mo[j]])
        elif j == 1:
            maxp= max(maxp, l[i][mo[j]])
        elif j == 2:
            maxt= max(maxt, l[i][mo[j]])
girl = []
pizza = []
taxi = []
for i in l:
    for j in range(3):
        if j == 0:
            if maxg == l[i][mo[j]]:
                girl.append(i)
        elif j == 1:
            if maxp == l[i][mo[j]]:
                pizza.append(i)
        elif j == 2:
            if maxt == l[i][mo[j]]:
                taxi.append(i)
strg = ""
strt = ""
strp = ""
for i in range(len(girl)):
    if i == len(girl)-1:
        strg+=" "+girl[i]+'.'
    else:
        strg+=" "+girl[i]+','
for i in range(len(taxi)):
    if i == len(taxi)-1:
        strt+=" "+taxi[i]+'.'
    else:
        strt+=" "+taxi[i]+','
for i in range(len(pizza)):
    if i == len(pizza)-1:
        strp+=" "+pizza[i]+'.'
    else:
        strp+=" "+pizza[i]+','
s = "If you want to call a taxi, you should call:"+strt
s1 = "If you want to order a pizza, you should call:"+strp
s2 = "If you want to go to a cafe with a wonderful girl, you should call:"+strg
print(s)
print(s1)
print(s2)
