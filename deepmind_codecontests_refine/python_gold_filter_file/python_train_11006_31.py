n = int(input().strip())
hund = n // 100
n = n % 100
twen = n // 20
n = n % 20
ten = n // 10
n = n % 10
five = n // 5
n = n % 5
one = n // 1
print(int(hund + twen + ten + five + one))