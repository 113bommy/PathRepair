word = input()
w = ''
for i in word:
    j = str.lower(i)
    if j not in ['a','e','i','o','u','y']:
        w = w + '.' + j
print(w)