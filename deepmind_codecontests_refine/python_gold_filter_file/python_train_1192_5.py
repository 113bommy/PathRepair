keyboard = '''qwertyuiopasdfghjkl;zxcvbnm,./'''
d = dict()
for i in range(0, len(keyboard)):
    d[keyboard[i]] = i
t = input()
string = input()
k = 0
if t == "L":
    k = 1;
if t == "R":
    k = -1
result = str()
for i in range(0, len(string)):
    index = d[string[i]] + k
    if index < 0:
        len(keyboard) - 1
    if index > len(keyboard) - 1:
        index = 0
    result = result + keyboard[index]


print(result)