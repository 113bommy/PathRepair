n = int(input())
s = input()
prev = False
output = ""
for i in range(n):
    if s[i] in "aeiouy":
        if prev != True:
            output += s[i]
        prev = True
    else:
        output += s[i]
        prev = False
print(output)