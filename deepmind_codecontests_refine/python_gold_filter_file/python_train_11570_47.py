n = int(input())
angka = [2,3,4,5,6,7]

for i in range(n):
    hasil = 0
    dice = int(input())
    for j in angka:
        if dice >= j:
            hasil += dice // j
            dice = dice % j
        if dice == 0:
            break
    print(hasil)

