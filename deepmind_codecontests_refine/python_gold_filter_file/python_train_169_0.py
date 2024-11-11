n = int(input())
s = input()
p = s[0]
d = dict()
for i in s[1:]:
    if (p,i) not in d:
        d[(p,i)] = 1
    else:
        d[(p,i)] += 1
    p = i
num_value = 0
K = ('', '')
for k,v in d.items():
    if v > num_value:
        num_value = v
        K = k
print(''.join(K))