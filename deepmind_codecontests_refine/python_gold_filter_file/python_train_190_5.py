S = input()
s = t = 0
for c in S:
    if c == 'S':
        s += 1
    else:
       if s > 0:
           s -= 1
       else:
           t += 1
print(s+t)