n = int(input())
inpt = input()
L = inpt.count('L')
R = inpt.count('R')
U = inpt.count('U')
D = inpt.count('D')


count = 0
count += 2*min(L, R) + 2*min(U, D)
print (count)
