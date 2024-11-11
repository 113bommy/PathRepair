glas = ['a', 'o', 'u', 'i', 'e']
s = input()
i = 0
a = 'YES'
while i < len(s):
    if not s[i] in glas and s[i] != 'n':
        if i != len(s) - 1:
            if not s[i + 1] in glas:
                a = 'NO'
                break
        else:
            a = "NO"
            break
    i += 1
print(a)