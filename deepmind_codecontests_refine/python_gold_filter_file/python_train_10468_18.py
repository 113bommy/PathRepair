str = input()
tmp = str[0]
num = int(str[1])

flag = 8
if tmp in ['a','h'] and num in [1,8]:
	flag=3

elif tmp in ['a','h']:
	flag=5

elif num in [1,8]:
	flag=5

print(flag)
