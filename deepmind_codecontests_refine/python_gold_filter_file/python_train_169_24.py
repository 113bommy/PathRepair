from itertools import product

n = int(input())
a = input()

perm = product(set(a), repeat=2)

temp_dict = {}

for iteration in perm:
    temp_dict[''.join(iteration)] = 0

for i in range(n - 1):
    temp_dict[a[i:i+2]]+=1

mx = 0
s = ''

for key, value in temp_dict.items():
    if value > mx:
        mx = value
        s = key

print(s)
