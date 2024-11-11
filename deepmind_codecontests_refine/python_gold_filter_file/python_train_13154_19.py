s = input()
dic = {}

for each in s:
    if each not in dic:
        dic[each] = 0
    dic[each] +=1
x = list(dic)
if len(x)%2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")