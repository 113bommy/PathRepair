L = int(input())

print(L.bit_length(), 2*(L.bit_length()-1) + (bin(L)[3:]).count('1'))
for i in range(L.bit_length()-1,0,-1):
    print(i,i+1,0)
    print(i,i+1,1<<(i-1))
    if (L >> i-1) & 1:
        print(i,L.bit_length(),L>>i<<i)
