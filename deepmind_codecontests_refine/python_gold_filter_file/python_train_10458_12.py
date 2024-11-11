ls = list(map(int, input().split()))
freq = {}
for x in ls:
    if not x in freq:
        freq[x] = 0
    freq[x] += 1
flag = None
for (k, v) in freq.items():
    if v >= 4:
        flag = k
        break
if not flag:
    print('Alien')
else:
    if freq[k] == 4:
        freq.pop(k)
    else:
        freq[k] -= 4
    if len(freq) == 2:
        print('Bear')
    else:
        print('Elephant')
