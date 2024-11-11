shift = input()
s = input()

layout = 'qwertyuiopasdfghjkl;zxcvbnm,./'
res = ''

for i in s:
    if shift == 'R':
        res += layout[(layout.index(i) - 1)]
    else:
        res += layout[(layout.index(i) + 1)]

print (res)