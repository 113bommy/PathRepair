a,b,c=map(int,input().split())
e=a-b|b-c
print((e!=b%2)*(e^e-1).bit_length()-1)