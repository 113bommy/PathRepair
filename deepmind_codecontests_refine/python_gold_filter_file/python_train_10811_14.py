s = input()
s = input()
x = 0
l_x = [0]
for c in s:
  x += 1 if c == 'I' else -1
  l_x.append(x)
    
print(max(l_x))