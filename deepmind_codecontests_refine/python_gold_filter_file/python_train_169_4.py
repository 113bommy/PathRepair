t = int(input())
s = input()
ls = []
setls = {}
for i in range(0,len(s)-1):
    ls.append(s[i]+s[i+1])

setls = set(ls)
max = " "
maxval = 0
for items in setls:
    
    temp = ls.count(items)
    if temp > maxval:
        maxval = temp  
        # print('changing maxval to ', temp)
        max = items
print(max)

    