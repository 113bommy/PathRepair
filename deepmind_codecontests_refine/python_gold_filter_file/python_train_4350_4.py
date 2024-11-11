#abc171c
n=int(input())
s=''
while n:
 n-=1
 s+=chr(n%26+97)
 n//=26
print(s[::-1])
