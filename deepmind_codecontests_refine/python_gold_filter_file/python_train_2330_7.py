t = input()
temp = t.split()
n = int(temp[0])
t = int(temp[1])
s = input()
temp = s.split()
books = [int(i) for i in temp]
count = 0
time = 0
j = 0
for i in range(len(books)):
    time = time + books[i]
    if (time <= t):
        count += 1
    else:
        time = time - books[j]
        j += 1

print(count)
