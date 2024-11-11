a = 1
for i in range(int(input()),1,-1):
    a = a * i % 1000000007
print(a)