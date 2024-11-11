st = input()
st += "0"
ind = []

distance = 0
vowels = ["A", "E", "I", "O", "U", "Y"]
for i in st:
    distance += 1
    if(i in vowels):
        ind.append(distance)
        distance = 0
ind.append(distance)
print(max(ind))