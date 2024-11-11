n=int(input())
for c in input():print(chr(65+(ord(c)-65+n)%26),end="")