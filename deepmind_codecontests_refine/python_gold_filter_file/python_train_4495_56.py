a = input()
b = ""


for i in a:
    if i not in "aeiouAEIOUyY":
        b += "."
        b += i.lower()
print(b)
