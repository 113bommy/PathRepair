n=int(input())
z=""
while n>0:
  n=n-1 ##for tracking last character
  z+= chr( n%26 + ord('a') )
  n=n//26
print(z[::-1])
