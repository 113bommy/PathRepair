s = input()
test = 'hello'
num = 0
for i in s:
    if num<5 and test[num]==i:
        num +=1
if num==len(test) :
    print('YES')
else:
    print('NO')