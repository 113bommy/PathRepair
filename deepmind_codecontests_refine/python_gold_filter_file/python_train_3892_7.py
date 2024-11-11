a = input()
keys = {}
for i in a:
    if i in keys:
        keys[i] += 1
    else:
        keys[i]=1

#print(keys)    
n = 0
for i in keys.keys():
    if keys[i] % 2 == 1:
        n += 1
if  n < 2 or n % 2 == 1:
    print("First")
else:
    print("Second")

# Fri Oct 16 2020 11:56:59 GMT+0300 (Москва, стандартное время)
