from math import log2 as log
from math import factorial as fact
from itertools import permutations
n = int(input())
digits = str(n)
no7 = digits.count('7')
no4 = digits.count('4')
covered = 2*(2**(len(digits) - 1) - 1)
binary = ''
for i in digits:
    if i == '4':
        binary += '0'
    else:
        binary += '1'

print(covered + int(binary, 2) + 1)

