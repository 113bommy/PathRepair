n = input()

k = len(n)
j = "9"*(k-1)

if n[1::] == j:
    print(int(n[0])+9*(k-1))
else:
    print(int(n[0])-1+9*(k-1))