
st = input()

frequency = [0]*26
even = 0
odd = 0

for s in st:
    frequency[ord(s) - 97] += 1

#print(frequency)
for i in frequency:
    if i%2 == 0:
        even += 1
    else:
        odd += 1

if odd <= 1 or odd%2 == 1:
    print("First")

elif odd%2 == 0:
    print("Second")
