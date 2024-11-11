mins = int(1e9)
nu8 = 0
for i in range(8):
    A = input()
    dem = 0
    for j in range(8):
        if A[j] == "B":
             dem += 1
    if dem < mins:
        mins = dem
    if dem == 8:
        nu8 += 1
print(nu8+mins%8)