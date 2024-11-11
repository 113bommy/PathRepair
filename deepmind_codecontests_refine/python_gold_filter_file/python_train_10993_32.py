n = int(input())

k = 0
while 5*(2**(k + 1) - 1) < n:
    k += 1

#print(k)

a = (n - 5*(2**k - 1) - 1)//(2**k)
if a == 0:
    print("Sheldon")
if a == 1:
    print("Leonard")
if a == 2:
    print("Penny")
if a == 3:
    print("Rajesh")
if a == 4:
    print("Howard")





