s1 = input()
s2 = input()
text = input()

s11 = s1.upper()
s22 = s2.upper()

result = ''
for i in text:
    if not i.isdigit():
        index = s1.find(i)
        if index >= 0:
            result += s2[index]
        else:
            result += s22[s11.find(i)]
    else:
        result += i
print(result)
