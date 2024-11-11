x = (input()).split()
count = 0
a = int(x[0])
b = int(x[1])
y = (input()).split()
k = 0
for j in range(len(y)):
    k = int(y[j])
    if k > b:
        k = k/2
        count += 2
    else:
        count += 1
print(count)