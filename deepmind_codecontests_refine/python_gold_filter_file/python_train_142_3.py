w = input()
x = []
for num in w:
    if num != "+":
        x.append(int(num))
x.sort()
nw = ""
for n in x:
    nw += str(n) + "+"
print(nw[:len(nw) -1])