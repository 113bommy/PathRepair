k = []
s = input().split(" ")
for i in s:
    k.append(int(i))
k.sort()
print(k[2]-k[0])
