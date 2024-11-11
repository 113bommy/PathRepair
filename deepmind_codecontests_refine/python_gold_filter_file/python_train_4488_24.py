#from random import random, randint
#from sys import stdout
import string

n, k = map(int, input().split())
s = input()

aktmin = n
for b in string.ascii_uppercase[:k]:
    aktmin = min(aktmin, s.count(b))

print(k*aktmin)
