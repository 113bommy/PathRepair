string = input()
hiedi = ["h", "e", "i", "d", "i"]
count = 0
while len(hiedi) != 0 and count<len(string):
    if string[count] == hiedi[0]:
        hiedi.remove(hiedi[0])
    count += 1

if len(hiedi) == 0:
    print("YES")
else:
    print("NO")


