''' Walk on Matrix
'''

def findpow2(integer):
    pow2 = 1
    while pow2 <= integer:
        pow2 *= 2
    return pow2

''' routine '''

k = int(input())

B = findpow2(k)
A = 2*B

print(3, 3)
print(A-1, A-1, B-1)
print(A-1, B, A-1)
print(B-1, A-1, k)
