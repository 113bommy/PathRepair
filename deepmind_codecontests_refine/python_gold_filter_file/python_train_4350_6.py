n=int(input())
s=''

while n>0:
    s=chr((n-1)%26+97)+s
    n=(n-1)//26
print(s)